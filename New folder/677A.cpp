#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h;
    cin >> n >> h;
    int hei[n];
    for(int i=0; i<n; i++){
        cin >> hei[i];
    }
    int wid = 0;
    for(int i=0; i<n; i++){
        if(hei[i] <= h){
            wid +=1;
        }
        else{
            wid += 2;
        }
    }

    cout << wid ;


}