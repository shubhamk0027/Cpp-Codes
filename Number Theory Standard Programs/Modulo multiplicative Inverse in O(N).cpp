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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)


const int N=2e6+5;
const int mod=1e9+7;

int mmi[N];
void buildMMI(){
      mmi[1]=1; 
      for(int i=2;i<N;i++) mmi[i]=(1LL*mmi[mod%i]*(mod-mod/i))%mod;
}

int main(){
      return 0;
}