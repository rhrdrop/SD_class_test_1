#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a,b,d;
    while(n--){
        cin >> a >> b ;
        if( a%b != 0){
            d= b - (a%b);
        }
        else{
            d=0;
        }
        cout << d << endl;
    }
}
