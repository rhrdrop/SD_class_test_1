#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    char s[n];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    int danik = 0, anton = 0;
    for(int i=0 ; i<n; i++){
        if(s[i] == 'A')
            anton++;
        else
            danik++;
    }
    if(anton > danik)
        cout << "Anton" << endl;
    else if(danik > anton)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}