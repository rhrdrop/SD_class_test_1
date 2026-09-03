#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    
    long long ans = 0;
    for (int i = 0; i < count; i++) {
        ans = ans * 2 + 1;
    }
    
    cout << ans << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}