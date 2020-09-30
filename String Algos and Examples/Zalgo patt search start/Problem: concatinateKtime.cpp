#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =5e5+1;

ll k;
int z[N];
ll solve(string &s){
	string ss=s+s+'$'+s+s+'?';
	// s+s to find a pattern of len >n!
	// just by comparing with s we cant cal the values!!
	int l=0,r=0,n=s.size();
	for(int i=1;i<ss.size()-1;i++){
		if(r<i){
			l=i,r=i-1;
			while(ss[r+1-l]==ss[r+1]) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-i+1) z[i]=z[i-l];
		else{
			l=i;
			while(ss[r+1-l]==ss[r+1]) r++;
			z[i]=r-l+1;
		}
	}
	ll res=0;
	// when concatiniating
	// add the z values of the kth block simply
	// add the z values of the (k-1)th (k-1) times
	// add ((k-2)(k-1)*n)/2 for all those blocks that are extending beyond all the blocks 
	for(int i=0;i<n;i++) {
		res+=z[3*n+1+i];
		res+=(k-1)*z[i+2*n+1];
		if(z[i+2*n+1]>=n && k>1) res+=(n*(k-1)*(k-2))/2;
	}
	return res; 
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s>>k;
		cout<<solve(s)<<"\n";
	}
	return 0;
}