#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    //prime number check
    bool isPrime = true;
    if (n <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    
    if (isPrime) {
        cout << "ALERT" << endl;
    } else {
        cout << "SAFE" << endl;
    }

}