#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        bool ok = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == k){ 
                ok = true;
            }
        }

        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}