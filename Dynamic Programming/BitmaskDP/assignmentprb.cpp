#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
const ll mod =1e9+7;
const int N =18;

int n, c[N+1][N+1];
int dp[1<<N+5];
int mn=INT_MAX;

void solve(int k, int mask){
    cerr<<"for mask"<<mask<<" "<<k<<"=>"<<dp[mask]<<"\n";
    if(k==n) return;
    for(int i=0;i<n;i++){
       if((mask&(1<<i))==0){
           dp[mask|(1<<i)]=min(dp[mask|(1<<i)],dp[mask]+c[k][i]);
           solve(k+1,mask|(1<<i));
       } 
    }
}

int easy(){
    int mx=(1<<n)-1;
    for(int i=0;i<=mx;i++) dp[i]=INT_MAX;
    dp[0] = 0;
    for(int mask = 0;mask<mx;mask++){
        int x = __builtin_popcount(mask);
        for (int j = 0;j<n;j++) 
            if(!(mask&(1<<j)))
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+c[x][j])
    }
    return dp[mx];   
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>c[i][j];
    for(int i=1;i<(1<<n)+2;i++) dp[i]=INT_MAX;
    solve(0,0);
    cout<<dp[(1<<n)-1]<<"\n";
    return 0;
}