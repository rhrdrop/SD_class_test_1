#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0, sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += 5 * i;
        if (sum + k <= 240) {
            count = i;
        } else {
            break;
        }
    }

    cout << count << endl;
    
}