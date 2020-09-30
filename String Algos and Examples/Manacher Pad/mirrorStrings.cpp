#include<bits/stdc++.h>
#define pb push_back

using namespace std;
const int N =2e6+1;

int p[N];
void  manacher(string &s){
	string ss="|";
	for(auto x:s) ss.pb(x),ss.pb('|');
	int mx=0,m=0,r=0,cnt=0;
	for(int i=1;i<ss.size()-1;i++){
		p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
		while(i-p[i]>=1 && ss[i+1+p[i]]==ss[i-p[i]-1]) p[i]++;
		if(r<i+p[i]) r=p[i]+i,m=i;
		mx=max(mx,p[i]);
	}
	for(int i=1;i<ss.size()-1;i++) if(mx==p[i]) cnt++;
	cout<<mx<<" "<<cnt<<"\n";
}

int main() {
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		manacher(s);
	}
	return 0;
}