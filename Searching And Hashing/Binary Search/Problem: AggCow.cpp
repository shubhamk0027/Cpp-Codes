#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

const ll mod =1e9+7;
const int NMAX =1e5+1;
int loc[NMAX],n,k;
using namespace std;


bool check(int m){
    int cnt=1,st=loc[0];
    for(int i=1; i<n;i++){
        if(loc[i]-st>=m){
            cnt++;
            st=loc[i];
        }
    }    
    // cerr<<"For m="<<m<<" "<<(cnt>=k);
    if(cnt>=k) return 1;
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0; i<n;i++) cin>>loc[i];
        sort(loc,loc+n);
        int lo=INT_MAX,hi=loc[n-1]-loc[0],mid;
        for(int i=1; i<n;i++) lo=min(lo,loc[i]-loc[i-1]);
        // cerr<<lo<<" "<<hi<<"\n";
        for(int i=0; i<30;i++){ // best! :P
            mid= (lo+hi)>>1;
            if(check(mid)) lo=mid;
            else hi=mid-1;
        }
        // this will help checking for the odd num as well if hi=odd and lo=even!
        if(check(lo+1)) lo++;
        cout<<lo<<"\n";
    }

    return 0;
}