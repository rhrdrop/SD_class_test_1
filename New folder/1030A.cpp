#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        
    }
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            flag = true;
            break;
        }
    }
    if(flag==true){
        cout << "HARD" << endl;
    }
    else{
        cout << "EASY" << endl;
    }
}