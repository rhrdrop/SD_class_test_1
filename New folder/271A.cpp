#include<bits/stdc++.h>
using namespace std;
int main(){
    int y;
    cin >> y;
    string d;
    while(true){
        y++;
        d = to_string(y);
        set<char> s(d.begin(), d.end());
        if(s.size() == d.size()){
            cout << d << endl;
            break;
        }
    
    }
}