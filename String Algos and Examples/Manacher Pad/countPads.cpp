#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int p[N];
ll manacher(string &s){
	ll cnt=0;
	int m=0,r=0;
	string ss="|";
	for(auto x:s) ss.pb(x),ss.pb('|');
	for(int i=1;i<ss.size()-1;i++){
		// ELSE INIT TO 0
        p[i]=(i<r)?min(p[m-(i-m)],r-i):0;
		
        while(i-p[i]>=1 && ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
		if(i+p[i]>r) r=i+p[i],m=i;

		cnt+=(p[i]+1)/2;// NOTE THIS!!
	}
	return cnt;
}

int main() {
	string s;
	cin>>s;
	cout<<manacher(s);
	return 0;
}