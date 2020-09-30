#include<bits/stdc++.h>

using namespace std;
const int N =11;

int mat[N][N],n,mx,mn;
int dp[1<<N];

void solve(int last, int mask){
    if(mask==mx) return; 
    for(int j=0;j<n;j++) if(!(mask&(1<<j)) && mat[j][last]){
        dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+mat[j][last]);
        solve(j,mask|(1<<j));
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    int m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++) {  
        cin>>a>>b>>c;    
        if(a>n||b>n) continue;
        mat[a-1][b-1]=mat[b-1][a-1]=c;
    }
    mx=(1<<n)-1;
    mn=mx;
    for(int j=0;j<n;j++){
        fill(dp,dp+mx+1,100000);
        dp[1<<j]=0; 
        solve(j,1<<j); mn=min(dp[mx],mn);
    }
    cout<<mn;   
    return 0;
}