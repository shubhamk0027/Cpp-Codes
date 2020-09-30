#include<bits/stdc++.h>
using namespace std;

void EE(long long a, long long b, long long& x, long long& y){
    if(a%b == 0){x=0,y=1;return;}
    EE(b,a%b,x,y);long long t = x;x = y;y = t - y*(a/b);
}
long long mmi(long long a,long long p){long long x,y;EE(a,p,x,y);x = (x+p)%p;return x;}
int main(){
    long long t,n,p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        if(n>=p) cout<<"0\n";
        else{
            long long res=-1+p;
            for(int i=n+1;i<p;i++) res=(1LL*res*mmi(i,p))%p;
            cout<<res<<"\n";
        }
    }
    return 0;
}