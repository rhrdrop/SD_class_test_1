#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;

    int best = x, worst = x, ans = 0;

    for (int i = 1; i < n; i++) {
        cin >> x;

        if (x > best) {
            ans++;
            best = x;
        } else if (x < worst) {
            ans++;
            worst = x;
        }
    }

    cout << ans;
    return 0;
}