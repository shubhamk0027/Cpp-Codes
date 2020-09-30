#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back

using namespace std;
const int N=1e6+10,M=1e5+10;

int ar[M],n,q,k;
ll res[N],cnt[N];

// we cant write this in a structure!!
int sp[M][20],LOG[M];
struct sparse{
    void build(){
        LOG[1]=LOG[0]=0;
        for(int i=2;i<M;i++) LOG[i]=LOG[i>>1]+1;
        for(int i=1;i<=n;i++) sp[i][0]=ar[i];
        for(int j=1;j<20;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)  // i+ fulllen -1 <=n
                sp[i][j]=__gcd(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
    int query(int l, int r){
        int lg=LOG[r-l+1];
        return __gcd(sp[l][lg],sp[r-(1<<lg)+1][lg]);
    }
};

void build(){
    sparse tb;
    tb.build();
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            int currgcd=tb.query(i,j);
            int lo=j,mid,hi=n,ans=j;
            while(lo<=hi){
                mid=(lo+hi)>>1;
                if(tb.query(i,mid)==currgcd) ans=mid,lo=mid+1;
                else hi=mid-1;
            }
            if(currgcd<N)
            cnt[currgcd]+=(ans-j+1);
            j=ans+1;
        }
    }
}

void build1(){
    int gg;
    // thos solution should work but is not working!
    map<int,int> next, old;
    for(int i=1;i<=n;i++){
        next=map<int,int>();
        if(ar[i]<N) cnt[ar[i]]++, next[ar[i]]++;
        for(auto pp: old) {
            gg=__gcd(pp.first,ar[i]);
            if(gg>=N) continue;
            next[gg]+=pp.second;
            cnt[gg]+=pp.second;
        }
        old=next;
    }
}

void  naive(){
    // for(int i=1,g=ar[i];i<=n;i++){ WA i might not be defined here!
    for(int i=1;i<=n;i++){
        int g=ar[i];
        for(int j=i;j<=n;j++) {
            g=__gcd(g,ar[j]);
            if(g<N) cnt[g]++;
        }
    }
}

void seive(){
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i) 
            res[j]+=cnt[i];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ar[i];
    // naive();
    build2();
    seive();
    cin>>q;
    while(q--) {
        cin>>k;
        cout<<res[k]<<"\n";
    }
    return 0;
}