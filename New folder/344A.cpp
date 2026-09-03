#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
    cin >> n;
    
    int groups = 1;
    string prev, curr;
    cin >> prev;
    
    for (int i = 1; i < n; i++) {
        cin >> curr;
        if (curr != prev) groups++;
        prev = curr;
    }
    
    cout << groups << endl;
    return 0;
}