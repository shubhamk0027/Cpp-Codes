//Minimum time to reach 0th from a position n when you jump by a prime factor of that block in 1 second

#include<bits/stdc++.h>
using namespace std;

const int MAX= 1000000;
bool isprime[MAX+1];
vector<vector<int>> primefactor(MAX+1,vector<int>());


void buildseive(){
    isprime[0]=isprime[1]=0;
    for(int i=2; i<=MAX;i++) isprime[i]=1;
    for(int i=2;i<=MAX;i++){
        if(!isprime[i]) continue;
        for(int j=i+i;j<=MAX;j+=i)
        isprime[j]=0,primefactor[j].push_back(i);
    }
}


int main(){
    int n;
    cin>>n;
    buildseive();
    int dp[MAX+1];
    int count;
    dp[0]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i]) {
            dp[i]=1; 
            continue;
        }
        count=100000000;
        for(auto j:primefactor[i])
            count=min(count,dp[i-j]);
        dp[i]=count+1;
    }
    cout<<dp[n];
    return 0;
}