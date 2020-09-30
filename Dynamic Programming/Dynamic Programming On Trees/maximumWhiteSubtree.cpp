#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define in(x) scanf("%d",&x)
#define inn(x,y) scanf("%d%d",&x,&y)
#define innn(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

using namespace std;
const int N=2e6+5;
const int mod=1e9+7;

vi adj[N];
int n,col[N];
int dpDw[N],dpUp[N],ans[N];

// to count the results of the children first
void dfsUp(int x, int p){
    if(col[x]) dpDw[x]++;
    else dpDw[x]--;
    for(auto xx: adj[x]) if(xx!=p){
        dfsUp(xx,x);
        if(dpDw[xx]>0) dpDw[x]+=dpDw[xx];
    }
}

void dfsDw(int x, int p){
    // calculating the final answers by computing answers from its parent
    if(col[x]) dpUp[x]++;
    else dpUp[x]--;

    int fromparent=0;
    for(auto xx: adj[x]){
        if(xx==p){
            if(dpDw[x]>0) fromparent=dpUp[p]-dpDw[x];
            else fromparent=dpUp[p];
            if(fromparent>0) dpUp[x]+=fromparent;
        }else{
            if(dpDw[xx]>0) dpUp[x]+=dpDw[xx];
        }
    }

    for(auto xx: adj[x]) if(xx!=p) dfsDw(xx,x);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=1;i<n;i++){
        int u,v;    
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }   
    dfsUp(1,0); // from its child
    dfsDw(1,0); // from its child and parent
    // for(int i=1;i<=n;i++) cerr<<dpDw[i]<<" "; cerr<<"\n";
    // for(int i=1;i<=n;i++) cerr<<dpUp[i]<<" "; cerr<<"\n";
    for(int i=1;i<=n;i++) cout<<dpUp[i]<<" "; 
    return 0;
}