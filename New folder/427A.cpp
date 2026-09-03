#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int fp = 0;
    int un = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == -1) {
            if (fp > 0)
                fp--;
            else
                un++;
        } else {
            fp += x;
        }
    }

    cout << un << endl;

    return 0;
}