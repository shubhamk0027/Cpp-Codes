#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define re cin>>
#define pr cout<<
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)


const int N=2e6+5;
const int mod=1e9+7;


vector<pii> adj[N];
int n,m,cnt[N];
ll ans;

// Count the sum of the distance for path(u,v) for each u[1,n] and v[1,n]
// such that no two have same u and no 2 have same v

// First of all, each of them will visit his own city(a person's city is initially the city corresponding to his own number).
// After this each of them will go to some other friend's city(may stay at their own city as well) such that no two friends go to the same city.

// distance is max when->

void dfs(int x,int p=0){
    cnt[x]++;
    for(auto xx: adj[x]) if(xx.first!=p){
        dfs(xx.first,x);
        cnt[x]+=cnt[xx.first];
        ans+=min(cnt[xx.first],n-cnt[xx.first])*1LL*xx.second;
    }
}

int main(){
    re n;
    rep1(i,n-1){
        int u,v,w;
        re u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1);
    pr ans*2;
    return 0;
}