#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    if(cin >> s){
        for(char c : s){
            if( c == ','){
                cout << " " ;
            }else if( islower(c)){
                cout << (char)toupper(c);
            }else if ( isupper(c)){
                cout << (char)tolower(c);
            }
        }
    }
}
