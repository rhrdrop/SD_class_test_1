#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int a[55];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > ans) {
                ans = a[i] - a[i - 1];
            }
        }

        int last = 2 * (x - a[n - 1]);
        if (last > ans) {
            ans = last;
        }

        cout << ans << endl;
    }
    
}