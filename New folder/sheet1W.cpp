#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,x;
    char p,q;
    cin>>a>>p>>b>>q>>x;
    if(p== '+'){
        if(q== '='){
            if(a+b==x){
                cout<<"Yes";
            }
            else{
                cout<< a+b;
            }
        }
    }
    else if(p== '-'){
        if(q== '='){
            if(a-b==x){
                cout<<"Yes";
            }
            else{
                cout<< a-b;
            }
        }
    }
    else if(p== '*'){
        if(q== '='){
            if(a*b==x){
                cout<<"Yes";
            }
            else{
                cout<< a*b;
            }
        }
    }
}