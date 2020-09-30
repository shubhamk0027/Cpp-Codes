// count the number of ways to got a number multiple of all the numbers from 1..10
#include<bits/stdc++.h>
#define ll int64_t
#define pb push_back
#define vi vector<int>

using namespace std;
const int N =1e4+5;
const int mod =1e9+7;
const int M =2520;

vi vv;
int z[2*N];

void zalgo(string &p, string &t){
	int l=0,r=0;
	vv.pb(-1);
	string ss=p+'|'+t+'?';
	for(int i=1;i<ss.size();i++){
		if(r<i){
			l=i,r=i-1;
			while(ss[r+1]==ss[r-l+1]) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-i+1) z[i]=z[i-l];
		else{
			l=i;
			while(ss[r+1]==ss[r-l+1]) r++;
			z[i]=r-l+1;
		}
		if(i>p.size() && z[i]==p.size()) vv.pb(i-p.size());
	}
}
int dp[N][M];
int solve(){
	// SINCE THE NUMBER OF WAYS ARE LIMITED WE CAN TAKE THAT AS OUR BENIFIT
	for(int i=1;i<vv.size();i++){
		// excluding and including j!
		for(int j=0;j<M;j++){
			dp[i][j]= (dp[i][j]+dp[i-1][j])%mod;
			dp[i][(j*vv[i])%M]= (dp[i][(j*vv[i])%M]+dp[i-1][j])%mod;
		}
		dp[i][(vv[i])%M]++;
	}
	return dp[vv.size()-1][0];
}

int main() {
	string p,t;
	cin>>p>>t;
	zalgo(p,t);
	cout<<solve();
	return 0;
}