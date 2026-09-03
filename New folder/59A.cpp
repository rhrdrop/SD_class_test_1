#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int upper = 0, lower = 0;
    for (int i = 0; i < n; i++){
        if (isupper(s[i])){
            upper++;
        }else{
            lower++;
        }
    }

    if (upper > lower){
        for (int i = 0; i < n; i++){    
        s[i] = toupper(s[i]);
         }
         cout << s << endl;
    }else{
        for (int i = 0; i < n; i++){    
        s[i] = tolower(s[i]);
         }
         cout << s << endl;
    }


}