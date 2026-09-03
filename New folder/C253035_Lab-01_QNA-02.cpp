#include<bits/stdc++.h>
using namespace std;
int main(){

     int a,b,c;
     cout<<"Enter three numbers: ";
     cin>>a>>b>>c;
        int maximum = max({a,b,c});
        int minimum = min({a,b,c});
     cout<<"Maximum: "<<maximum<<endl;
     cout<<"Minimum: "<<minimum<<endl;
    
     return 0;
}


