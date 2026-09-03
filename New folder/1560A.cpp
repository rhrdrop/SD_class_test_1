#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> seq;

    for (int x = 1; seq.size() < 1000; x++) {
        int temp = x;
        bool has3 = false;

        while (temp > 0) {
            if (temp % 10 == 3) {
                has3 = true;
                break;
            }
            temp /= 10;
        }

        if (x % 3 != 0 && !has3) {
            seq.push_back(x);
        }
    }

    while (t--) {
        int n;
        cin >> n;
        cout << seq[n - 1] << '\n';
    }
}