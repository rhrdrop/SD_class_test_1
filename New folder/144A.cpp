#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int pos_max = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[pos_max]) pos_max = i;
    }

    int pos_min = 0;
    for(int i = 1; i < n; i++){
        if(a[i] <= a[pos_min]) pos_min = i;  
    }

    int count = pos_max + (n - 1 - pos_min);

    if(pos_min < pos_max) count--;

    cout << count << endl;
}