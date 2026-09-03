#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    int odd = 0, even = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sum += x;

        if (x % 2 == 0)
            even++;
        else
            odd++;
    }

    if (sum % 2 == 0){
        cout << even << endl;
    }
    else{
        cout << odd << endl;
    }
}