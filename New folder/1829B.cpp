#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int x;
        int cnt = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;

            if (x == 0) {
                cnt++;
                if (cnt > mx){
                     mx = cnt;
                   }
            } else {
                cnt = 0;
            }
        }

        cout << mx << endl;
    }

}