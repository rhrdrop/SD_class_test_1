#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        long long cost1 = n * a;
        long long cost2 = ((n + 2) / 3) * b;
        long long cost3 = (n / 3) * b + (n % 3) * a;
        long long ans = min(cost1, min(cost2, cost3));
        cout << ans << "\n";
    }
    return 0;
}