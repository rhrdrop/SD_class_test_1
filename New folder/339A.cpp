#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    string n ,p;
    for (int i = 0; i < s.size(); i++){
         if (s[i] != '+'){
            n += s[i];
            p += '+';
         }
    }
    sort(n.begin(), n.end());
    //cout << n << endl;

    for (int i = 0; i < n.size(); i++){
        cout << n[i];
        if (i != n.size() - 1){
            cout << "+";
        }
    }
}