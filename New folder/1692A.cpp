#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int count = 0;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a<b) count++;
        if(a<c) count++;
        if(a<d) count++;

        cout << count << endl;

         count = 0;
    }
    
}