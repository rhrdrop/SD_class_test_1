#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int maxp = max(n, m);
    int num = 6 - maxp + 1; 
    int den = 6;
    int g = __gcd(num, den);
    cout << num/g << "/" << den/g << endl;
}