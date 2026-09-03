#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    int max = 0;
    int pass = 0;
    int a[n], b[n];
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i=0; i<n; i++){
      pass = pass + b[i] - a[i];
      if(pass > max){
        max = pass;
      }
    
    }
    cout << max << endl;
}