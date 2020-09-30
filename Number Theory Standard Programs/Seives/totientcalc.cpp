#include<bits/stdc++.h>
using namespace std;
const long long mod=109546051211;
const long long base=10000000; 

int main(){
    int t,n;
    cin>>t;
    const int MAX =1000000;
    int mulprime[MAX+1],mulprimeless[MAX+1];
    for(int i=0; i<=MAX;i++) mulprime[i]=mulprimeless[i]=1;

    for(int i=2; i<=MAX;i++){
        if(mulprime[i]==1)
        for(int j=i;j<=MAX;j+=i) 
        mulprime[j]=mulprime[j]*i,mulprimeless[j]=mulprimeless[j]*(i-1);
    }
    
    while(t--){
        cin>>n;
        cout<<(n/mulprime[n])*mulprimeless[n]<<"\n";
    }
    return 0;
}