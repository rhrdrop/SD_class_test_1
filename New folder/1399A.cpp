#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, a[55];
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        bool ok = true;

        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 1) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}