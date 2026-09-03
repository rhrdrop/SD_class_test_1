#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;
    int s = 0, d = 0;
    bool turn = true;

    while (l <= r) {
        int x;
        if (a[l] > a[r]) {
            x = a[l];
            l++;
        } else {
            x = a[r];
            r--;
        }

        if (turn) s += x;
        else d += x;

        turn = !turn;
    }

    cout << s << ' ' << d;
    return 0;
}