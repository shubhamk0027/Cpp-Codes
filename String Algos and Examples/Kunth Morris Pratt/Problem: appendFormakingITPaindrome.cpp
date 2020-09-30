#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int lps[N];
string kmp(string &ss){
	string s=ss;
	reverse(s.begin(),s.end());
	s=s+"$"+ss;
	int len=0;
	for(int i=1;i<s.size();i++){
		while(len && s[i]!=s[len]) len=lps[len-1];
		if(s[i]==s[len]) lps[i]=++len;
		else lps[i]=len=0;
	}
	s=ss.substr(0,ss.size()-len);
	reverse(s.begin(),s.end());
	return ss+s;
}

int main() {
	string s;
	while(cin>>s){
		cout<<kmp(s)<<"\n";
	}
	return 0;
}