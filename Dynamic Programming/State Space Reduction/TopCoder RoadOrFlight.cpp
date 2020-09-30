// STATE SPACE REDUCTION!!!!

#include<bits/stdc++.h>
#define ll long long
using namespace std;

// TIME LIMIT- > 840ms;
// Memory Limit-> 64 mb!;
ll dp1[2][45];
ll dp2[2][45];
class RoadOrFlightHard{
    public:
    ll minTime(int n, int rf, int rp, int ra, int rm,int ff, int fp, int fa, int fm,int k){
        vector<ll> road(n+1),flight(n+1);
        road[1]=rf%rm;
        flight[1]=ff%fm;
        for(int i=2;i<=n;i++){
            road[i]=(road[i-1]*rp+ra)%rm;
            flight[i]=(flight[i-1]*fp+fa)%fm;
        }
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);
        for(int i=1;i<=n;i++){
            bool curr =i%2;
            dp1[curr][0]=dp1[!curr][0]+road[i];
            dp2[curr][0]=LONG_LONG_MAX;
            for(int j=1;j<=k;j++){
                dp1[curr][j]=min(min(dp1[!curr][j],dp2[!curr][j]),min(dp1[!curr][j-1],dp2[!curr][j-1]));
                dp2[curr][j]=min(dp2[!curr][j],min(dp2[!curr][j-1],dp1[!curr][j-1]));
                dp1[curr][j]=min(dp1[curr][j-1],dp1[curr][j]+road[i]);
                dp2[curr][j]=min(dp2[curr][j-1],dp2[curr][j]+flight[i]);
            }
        }
        ll res=LONG_LONG_MAX;
        for(int i=0;i<=k;i++) res=min(res,min(dp1[n%2][i],dp2[n%2][i]));
        return res;
    }
};

int main(){
    RoadOrFlightHard rh;
    int t=130;
    ll x;
    int n,rf,rp,ra,rm,ff,fp,fa,fm,k;
    char c;
    for(int i=0;i<t;i++){
        cin>>n>>c>>rf>>c>>rp>>c>>ra>>c>>rm>>c>>ff>>c>>fp>>c>>fa>>c>>fm>>c>>k>>x;
        if(x!=rh.minTime(n,rf,rp,ra,rm,ff,fp,fa,fm,k)) cout<<i+1<<"\n";
        else cerr<<"Passed!\n";
    }
}

