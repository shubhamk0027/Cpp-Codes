#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int lps[N];
int kmp(string s){
	// find the length of the longest prefix which is also a suffix at the last index, this might help n finding the period!
	int len=0;
	for(int i=1;i<s.size();i++){
		while(len && s[i]!=s[len]) len=lps[len-1];
		if(s[i]==s[len]) lps[i]=++len;
		else lps[i]=len=0;
	}
	return len;
}

int main() {
	string s;
	while(cin>>s){
		if(s=="*") break;
		int x=kmp(s),n=s.size();
		if(n%(n-x)==0) cout<<n/(n-x)<<"\n";
		else cout<<1<<"\n";
	}
	return 0;
}