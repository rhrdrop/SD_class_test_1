#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int sum=0;
    for(int i=1; i<=n; i++){

        int x=i;
        int s=0;
        while(x>0){
            s+=x%10;
            x/=10;
        }
        if(s>=a && s<=b){
            sum+=i;
        }
    }
    cout<<sum<<endl;

}