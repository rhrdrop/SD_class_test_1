#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s , t;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        
        t += tolower(s[i]);
    }
    if(t == s){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
