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

int n,dp[1<<18],mat[N][N];
int mx,mn;

// O(N*2^N)
void solve(int mask,int last){
    cout<<mask<<" "<<dp[mask]<<"\n";
    if(mask==mx) return;
    for(int i=0;i<n;i++) if(!(mask&(1<<i))){
        if(last!=-1){
            if(mat[last][i]) dp[mask|(1<<i)]=max(dp[mask|(1<<i)],dp[mask]+!mat[last][last]);
            solve(mask|(1<<i),-1);
        }else{
            dp[mask|(1<<i)]=max(dp[mask|(1<<i)],mat[i][i]+dp[mask]);
            solve(mask|(1<<i),i);
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        char x;
        cin>>n;
        mx=(1<<n)-1;
        fill(dp,dp+mx,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                cin>>mat[i][j];
            }
        dp[1]=mat[0][0];
        solve(1,0);
        cout<<dp[mx];
    }
    return 0;
}