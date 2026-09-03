#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[105];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        int minsum = 2000000000;
        
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {

                int csum = a[i] + a[j] + j - i;
                if (csum < minsum) {
                    minsum = csum;
                }
                
            }
        }
        cout << minsum << endl;
    }
    return 0;
}