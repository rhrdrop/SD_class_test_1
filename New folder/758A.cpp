#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    int max = 0;
    for (int i = 0; i < t ; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int burl = 0;
    for (int i = 0; i < t; i++) {
        if (arr[i] < max) {
            burl += max - arr[i];
        
        }
    }
    cout << burl << endl;
}