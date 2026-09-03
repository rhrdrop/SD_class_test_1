"""
Apex Local — offline crypto TA assistant
=========================================

Three layers, one file:
  1. Data Fetcher   -> pulls OHLCV candles from Binance's public REST API
                       (no key needed for klines)
  2. The AI Brain   -> sends a compact summary of the candles to a local
                       Ollama model with an SMC-style system prompt, and
                       asks it to return ONLY a JSON object describing an
                       entry zone / stop-loss / take-profit read
  3. Rendering      -> draws candles with lightweight-charts-python and
                       overlays the AI's zone as horizontal lines

This is a decision-support toy, not a signal service. The model can be
wrong, Binance data can gap, and nothing here is financial advice —
treat the output as one input into your own risk decision.

Setup
-----
    pip install requests pandas lightweight-charts

    # Ollama (https://ollama.com) must be installed and running:
    ollama pull llama3.1      # or any instruction-tuned model you like
    ollama serve               # usually starts automatically after install

Run
---
    python apex_local.py --symbol BTCUSDT --micro 1h --macro 4h --model llama3.1

    # see all options:
    python apex_local.py --help
"""

import argparse
import json
import sys
import textwrap

import pandas as pd
import requests

BINANCE_KLINES_URL = "https://api.binance.com/api/v3/klines"

SYSTEM_PROMPT = """You are Apex, a technical-analysis assistant. You analyze the
OHLCV candle data given to you and produce a single trade "read" using
Smart Money Concepts: order blocks, fair value gaps, liquidity sweeps,
break of structure / change of character, and basic volume context.

Rules:
- Anchor to the macro-timeframe candles first. Only take a setup against
  the macro trend if the macro data itself shows a clear exhaustion /
  CHOCH pattern.
- Never claim certainty. Frame everything as probabilistic.
- Only reference price levels that are actually present in, or a small
  and clearly-labeled projection just beyond, the candle data you were
  given. Do not invent round numbers that aren't grounded in the data.
- Target a minimum 1:3 reward-to-risk between entry and TP1. If you
  cannot construct one from this data, say so in "notes" instead of
  forcing a setup.
- Output ONLY a single JSON object. No markdown fences, no prose outside
  the JSON. Use exactly this schema:

{
  "macro_bias": "1-2 sentence summary of the higher timeframe trend",
  "entry_zone": {"top": <number>, "bottom": <number>},
  "stop_loss": {"price": <number>, "reason": "why the setup is void here"},
  "take_profit": [
    {"label": "TP1", "price": <number>},
    {"label": "TP2", "price": <number>}
  ],
  "risk_reward": "e.g. 1:3.2",
  "notes": "short caveats, or why no clean setup exists right now"
}
"""


def fetch_klines(symbol: str, interval: str, limit: int = 200) -> pd.DataFrame:
    """Pull candles from Binance's public klines endpoint."""
    params = {"symbol": symbol.upper(), "interval": interval, "limit": limit}
    resp = requests.get(BINANCE_KLINES_URL, params=params, timeout=15)
    resp.raise_for_status()
    raw = resp.json()

    df = pd.DataFrame(raw, columns=[
        "open_time", "open", "high", "low", "close", "volume",
        "close_time", "quote_volume", "trades",
        "taker_base_vol", "taker_quote_vol", "ignore",
    ])
    df["time"] = pd.to_datetime(df["open_time"], unit="ms")
    for col in ("open", "high", "low", "close", "volume"):
        df[col] = df[col].astype(float)

    return df[["time", "open", "high", "low", "close", "volume"]]


def summarize_for_prompt(df: pd.DataFrame, label: str, max_rows: int = 120) -> str:
    """Compact CSV-ish text block so the prompt doesn't blow up on long history."""
    trimmed = df.tail(max_rows).copy()
    trimmed["time"] = trimmed["time"].dt.strftime("%Y-%m-%d %H:%M")
    lines = [f"{label} candles (oldest -> newest, {len(trimmed)} rows):",
             "time,open,high,low,close,volume"]
    for row in trimmed.itertuples(index=False):
        lines.append(f"{row.time},{row.open},{row.high},{row.low},{row.close},{row.volume}")
    return "\n".join(lines)


def build_user_prompt(symbol: str, macro_df: pd.DataFrame, macro_interval: str,
                       micro_df: pd.DataFrame, micro_interval: str) -> str:
    parts = [
        f"Symbol: {symbol}",
        f"Macro timeframe: {macro_interval}. Micro timeframe: {micro_interval}.",
        summarize_for_prompt(macro_df, f"MACRO ({macro_interval})", max_rows=100),
        summarize_for_prompt(micro_df, f"MICRO ({micro_interval})", max_rows=150),
        "Using the rules in the system prompt, return the JSON object now.",
    ]
    return "\n\n".join(parts)


def call_ollama(model: str, user_prompt: str, host: str = "http://localhost:11434") -> dict:
    """Chat with a local Ollama model, forcing valid-JSON output."""
    try:
        resp = requests.post(
            f"{host}/api/chat",
            json={
                "model": model,
                "messages": [
                    {"role": "system", "content": SYSTEM_PROMPT},
                    {"role": "user", "content": user_prompt},
                ],
                "format": "json",   # Ollama enforces syntactically valid JSON
                "stream": False,
            },
            timeout=180,
        )
        resp.raise_for_status()
    except requests.exceptions.ConnectionError:
        sys.exit(
            "Couldn't reach Ollama at "
            f"{host}. Is it running? Try `ollama serve` in another terminal."
        )

    content = resp.json()["message"]["content"]
    try:
        return json.loads(content)
    except json.JSONDecodeError:
        sys.exit(f"Model didn't return valid JSON. Raw output:\n{content}")


def print_analysis(analysis: dict) -> None:
    print("\n" + "=" * 60)
    print("MACRO BIAS")
    print(textwrap.fill(analysis.get("macro_bias", "n/a"), 60))

    ez = analysis.get("entry_zone", {})
    sl = analysis.get("stop_loss", {})
    tps = analysis.get("take_profit", [])

    print("\nENTRY ZONE : {} - {}".format(ez.get("bottom"), ez.get("top")))
    print("STOP LOSS  : {}  ({})".format(sl.get("price"), sl.get("reason", "")))
    for tp in tps:
        print("{:<10}: {}".format(tp.get("label", "TP"), tp.get("price")))
    print("RISK:REWARD: {}".format(analysis.get("risk_reward", "n/a")))
    print("\nNOTES:", textwrap.fill(analysis.get("notes", ""), 60))
    print("=" * 60 + "\n")


def render_chart(symbol: str, micro_interval: str, micro_df: pd.DataFrame, analysis: dict):
    from lightweight_charts import Chart

    chart = Chart()
    chart.legend(visible=True)
    try:
        chart.watermark(f"{symbol}  {micro_interval}")
    except Exception:
        pass  # older lib versions may not expose watermark()

    chart.set(micro_df)

    ez = analysis.get("entry_zone") or {}
    if "top" in ez:
        chart.horizontal_line(ez["top"], color="rgba(0, 200, 0, 0.6)",
                               style="dashed", text="Entry top")
    if "bottom" in ez:
        chart.horizontal_line(ez["bottom"], color="rgba(0, 200, 0, 0.6)",
                               style="dashed", text="Entry bottom")

    sl = analysis.get("stop_loss") or {}
    if "price" in sl:
        chart.horizontal_line(sl["price"], color="rgba(255, 0, 0, 0.8)",
                               style="solid", text="SL")

    for tp in analysis.get("take_profit", []):
        if "price" in tp:
            chart.horizontal_line(tp["price"], color="rgba(0, 120, 255, 0.8)",
                                   style="solid", text=tp.get("label", "TP"))

    chart.show(block=True)


def main():
    ap = argparse.ArgumentParser(description="Local SMC-style crypto TA via Ollama")
    ap.add_argument("--symbol", default="BTCUSDT", help="e.g. BTCUSDT, ETHUSDT")
    ap.add_argument("--macro", default="4h", help="Macro timeframe, e.g. 4h, 1d")
    ap.add_argument("--micro", default="1h", help="Micro timeframe, e.g. 15m, 1h")
    ap.add_argument("--macro-limit", type=int, default=100)
    ap.add_argument("--micro-limit", type=int, default=200)
    ap.add_argument("--model", default="llama3.1", help="Ollama model name")
    ap.add_argument("--ollama-host", default="http://localhost:11434")
    ap.add_argument("--no-chart", action="store_true", help="Skip the chart window, just print the read")
    args = ap.parse_args()

    print(f"Fetching {args.symbol} candles from Binance...")
    macro_df = fetch_klines(args.symbol, args.macro, args.macro_limit)
    micro_df = fetch_klines(args.symbol, args.micro, args.micro_limit)

    prompt = build_user_prompt(args.symbol, macro_df, args.macro, micro_df, args.micro)

    print(f"Asking Ollama ({args.model}) for a read...")
    analysis = call_ollama(args.model, prompt, host=args.ollama_host)

    print_analysis(analysis)

    if not args.no_chart:
        render_chart(args.symbol, args.micro, micro_df, analysis)


if __name__ == "__main__":
    main()