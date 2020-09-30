// O(2^N)*N*N
#include<bits/stdc++.h>

using namespace std;
const int N =11;

int mat[N][N],n,mx,mn;
int dp[1<<N][N];

void solve(){
    mx=(1<<n)-1;
    mn=mx;
    for(int i=1;i<=mx;i++){
        int k = __builtin_popcount(i);
        if(k==1) continue; // ONLY NODE
        for(int j=0;j<n;j++){ // END NODE
            dp[i][j]=INT_MAX;
            for(int k=0;k<n;k++)    // INTERMEDIATE NODE k
                if((j!=k) && ((1<<j)&i) && ((1<<k)&i))
                    dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+mat[k][j]);
        }
    }
    for(int i=0;i<n;i++) mn=min(mn,dp[mx][i]);
}

int main() {
    int m,a,b,c;
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=10000;

    for(int i=0;i<m;i++) {  
        cin>>a>>b>>c;    
        if(a>n||b>n) continue;
        mat[a-1][b-1]=mat[b-1][a-1]=min(mat[a-1][b-1],c);  // same node can appear more than once
    }

    solve(); 
    cout<<mn<<"\n";  
    return 0;
}