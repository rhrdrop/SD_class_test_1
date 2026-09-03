#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,p,r;
    cin >> s;
    cin >> p;
    for(int i=0; i<s.size();i++){
        if(s[i]==p[i]){
            r+='0';
        }else{
            r+='1';
        }
    }
    cout << r << endl;
}

