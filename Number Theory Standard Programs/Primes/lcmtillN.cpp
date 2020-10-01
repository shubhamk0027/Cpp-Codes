#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod=1e9+7;
const int NMAX =1e6+1;
ll res[NMAX];
int isprime[NMAX]={1};
int gpf[NMAX]={1};

bool isPerfectPower(int n){
    int x = gpf[n];
    while(x<n) x=x*gpf[n];
    if(n==x) return 1;
    return 0;
}

void build(){
    for(int i=2; i<=NMAX;i++)
        if(isprime[i]) 
            for(int j=2*i;j<=NMAX;j+=i) isprime[j]=0;
    
    for(int i=0; i<NMAX;i++) gpf[i]=1; 
    for(int i=2; i<NMAX;i++)
        if(gpf[i]==1)
            for(int j=i; j<=NMAX;j+=i) gpf[j]=i;
            
    res[1]=1;
    for(int i=2;i<=NMAX;i++)
        if(isPerfectPower(i)) res[i]=(res[i-1]*gpf[i])%mod;
        else res[i]= res[i-1];
}

int main(){
    int t,n;
    cin>>t;
    build();
    while(t--){
        cin>>n;
        cout<<res[n]<<"\n";
    }
}