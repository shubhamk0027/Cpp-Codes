#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

ll a,b,n;
double log(ll x, ll y){
	return log10(x)/log10(y);
}

ll cntDigits(ll &m){
	return 1+ log(a,b)+m*log(m,b);
}

int main() {
	while(cin>>a>>n>>b){
		ll lo=1,hi=1e9,mid,lower,upper;
		while(lo<=hi){
			mid=(lo+hi)/2;
			// >= funciton = > lower bound
			if(cntDigits(mid)>=n) lower=mid,hi=mid-1;
			else lo=mid+1;
		}
		lo=1,hi=1e9;
		while(lo<=hi){
			mid=(lo+hi)/2;
			// > function = > upper bound
			if(cntDigits(mid)>n) upper=mid,hi=mid-1;
			else lo=mid+1;
		}
		cout<<upper-lower<<"\n";
	}
	return 0;
}