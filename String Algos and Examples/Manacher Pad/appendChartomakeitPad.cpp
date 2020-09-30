#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =5e5;

int p[N];
// ACCEPTED UVA
string manacher(string &s){
	string ss="&|";
	for(auto x:s) ss.pb(x),ss.pb('|');
	ss.pb('?');
	int m=0,r=0,mx=0;
	for(int i=2;i<ss.size()-2;i++){
		p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
		while(ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
		if(i+p[i]>r)r=i+p[i],m=i;
		if(i+p[i]==ss.size()-2) mx=max(mx,p[i]);
	}
	string res=s;
	for(int i=s.size()-mx-1;i>=0;i--) res.pb(s[i]); 
	return res;
}

int main() {
	string s;
	while(cin>>s){
		cout<<manacher(s)<<"\n";
	}
	return 0;
}