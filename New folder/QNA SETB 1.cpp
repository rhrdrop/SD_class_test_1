#include<bits/stdc++.h>
using namespace std;
int main(){
    int w;
    cin >> w ;
    double t = 0 ;
    if(w>500 && w<=600){
        t = (w-500)*0.2;
        cout << fixed << setprecision(1) << t << endl; 
    }
    else if(w>600 && w<=900){
        t = (w-500)*0.5;
        cout << fixed << setprecision(1) << t << endl; 
    }
    else if(w>900){
        t = (w-500)*1;
        cout << fixed << setprecision(1) << t << endl; 
    }
    else{
        cout << "0.0" << endl;
    }

    return 0;
}