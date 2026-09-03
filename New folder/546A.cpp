#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k , n , w , x ;
    cin >> k >> n >> w ;
    long long cost = ( k * w * ( w + 1 ) ) / 2;
    if ( cost > n ){
        x = cost - n ;
    }
    else {
        x = 0 ;
    }
    cout << x ;
}