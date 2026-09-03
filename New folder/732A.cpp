#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, r;
    cin >> k >> r;
    int n = 1;
    
    while (true) {
    int last = (k * n) % 10;

    if (last == 0 || last == r) {
        cout << n;
        break;
    }

    n++;
    }
}