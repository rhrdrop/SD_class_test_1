#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long d = llabs(a - b);
        cout << (d + 9) / 10 << '\n';
    }

    return 0;
}