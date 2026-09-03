#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    
    set<char>d;
    for(char c : s){
        
        if(c >= 'a' && c <= 'z'){
            d.insert(c);
        }
    }
    cout << d.size() << endl;

}