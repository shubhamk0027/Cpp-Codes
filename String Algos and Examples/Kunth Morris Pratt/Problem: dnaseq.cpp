// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=701&mosmsg=Submission+received+with+ID+23868629
#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int lps[350],val[350][350],mxlen;
vector<string> res;

// ITs not O(N2) but O(N2logN)!!!!
// SO better use trie instead!


// TO pass a substring Always use a char array!
// with gets(s) to get input 
// and puts("some string") to put something
// O(N2)->

void kmp(int b, string &s, string &p){
	int len=0;
	for(int i=1;i+b<p.size();i++){
		while(len && p[i+b]!=p[b+len]) len=lps[len-1];
		if(p[i+b]==p[b+len]) lps[i]=++len;
		else len=lps[i]=0;
	}
	val[b][0]=len=0;
	for(int i=0;i<s.size();i++){
		while(len && p[b+len]!=s[i]) len=lps[len-1];
		if(p[len+b]==s[i]) ++len;
		else len=0;
		val[b][i]=len;
	}
}

void solve(string &s,string &p){
	res.clear();
	mxlen=0;
	for(int b=0;b<p.size();b++)
	for(int j=0;j<s.size();j++) mxlen=max(mxlen,val[b][j]);
	if(!mxlen) return ;
	for(int b=0;b<p.size();b++)
	for(int j=0;j<s.size();j++) if(mxlen==val[b][j])
		res.push_back(s.substr(j-mxlen+1,mxlen));
	sort(res.begin(),res.end());
	res.resize(unique(res.begin(),res.end())-res.begin());
}

int main() {
	string s,p;
	int i=0;
	while(cin>>s>>p){
		if(i++) cout<<"\n";
		for(int j=0;j<p.size();j++) kmp(j,s,p);
		solve(s,p);
		if(res.size()) for(auto &xx:res) puts("hh");
		// by default adds a \n at the end of the output!
		else puts("No common sequence.");
	}
	return 0;
}