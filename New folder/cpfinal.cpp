#include<bits/stdc++.h>
using namespace std;

int main(){
     int N;
     cin >> N;
     vector<int> v(N);
     for(int i=0; i<N; i++){
         cin >> v[i];
     }
    sort(v.begin(), v.end());
    
    int count = 1;
    int maxcount = 1;
    int ans = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] == v[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxcount) {
            maxcount = count;
            ans = v[i];
        }
    }
    cout << ans << endl;
}