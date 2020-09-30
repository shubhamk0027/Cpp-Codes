#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

bool is(int &l,string &s){
	if(s.size()%l) return 0;
	for(int i=0;i<l;i++)
		for(int j=i;j<s.size();j+=l) if(s[j]!=s[i]) return 0;
	return 1;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i;
		for(i=1;i<s.size();i++) if(is(i,s)) break;
		cout<<i<<"\n";  // all the time print "\n"
		if(t) cout<<"\n"; // add space in between
	}
	return 0;
}