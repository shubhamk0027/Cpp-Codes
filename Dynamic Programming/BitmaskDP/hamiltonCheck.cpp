#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
const int N =21;

int n,m,a,b;
vi adj[N];
bool vis[N];
vector<int> p;

bool check(int x){
    if(p.size()==n) return 1;
    for(auto v:adj[x]) if(!vis[v]){
        vis[v]=1;
        p.pb(v);
        if(check(v)) return 1;
        p.pop_back();
        vis[v]=0;
    }
}


int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++) 
    cin>>a>>b, adj[a].pb(b),adj[b].pb(a); 

    for(int i=1;i<=n;i++){
        vis[i]=1;
        p.pb(i);
        if(check(i)) {
            cout<<"Yes";
            return 0;
        }
        p.pop_back();
        vis[i]=0;
    }
    cout<<"No";
    return 0;
}