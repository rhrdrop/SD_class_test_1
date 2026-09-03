#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    string s = to_string(n);

    long long int count = 0;
         for (int i = 0; i < s.size(); i++){
             if (s[i] == '4' || s[i] == '7'){
                 count++;
             }
         }

    string c = to_string(count);
    bool lucky = true;
    if(count == 0) lucky = false;
         for (int i = 0; i < c.size(); i++){
              if (c[i] != '4' && c[i] != '7'){
              lucky = false;
             }
    }

    if(lucky){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}