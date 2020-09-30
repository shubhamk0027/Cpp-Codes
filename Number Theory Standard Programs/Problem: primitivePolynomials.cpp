#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define re cin>>
#define pr cout<<
#define in(x) scanf("%d",&x)
#define inn(x,y) scanf("%d%d",&x,&y)
#define innn(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

const int N=2e6+5;
const int mod=1e9+7;

/*
If gcd given is 1 this means that all of them are not divisible by a single prime number
may be few or all except one will be there which will not be divisible by the prime
Polynomials with such cofficients are called primitive polynomials
1..n if all are divisible by prime p n+1 will not be 
1..m if all are divisible by prime p m+1 will not be
*/



int n,m,ar[N],br[N],p;
int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n>>m>>p;
    rep1(i,n) re ar[i];
    rep1(i,m) re br[i];
    n=1,m=1;
    while(ar[n]%p==0) n++;
    while(br[m]%p==0) m++;
    cout<<n+m-2<<"\n";
    return 0;
}