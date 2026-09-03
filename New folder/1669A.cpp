#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        if(t <= 1399) cout << "Division 4" << endl;
        else if(t <= 1599) cout << "Division 3" << endl;
        else if(t <= 1899) cout << "Division 2" << endl;
        else cout << "Division 1" << endl;
    }
}