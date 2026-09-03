#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int T;
    cin>>T;
    
    while(T--){
        int x,y;
        cin>>x>>y;
        
        int start = min(x,y);
        int end = max(x,y);
        
        int sum = 0;

        for(int i=start+1; i<end ; i++){
            if(i%2!=0){
            sum += i;
            }
        }
        cout<<sum<<endl;
    }


}