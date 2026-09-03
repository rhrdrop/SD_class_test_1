#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin >> s;
    set<char> distinct(s.begin(), s.end());
    int d = distinct.size();
     if(d % 2 == 0){
          cout << "CHAT WITH HER!" << endl;
         } else {
             cout << "IGNORE HIM!" << endl;
                }

return 0;

}