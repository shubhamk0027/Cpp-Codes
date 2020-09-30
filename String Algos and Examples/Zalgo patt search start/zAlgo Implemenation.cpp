#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

// Z algorithm->
// Z[i]= len of the longest substring 
// starting from i in S & is also a prefix in S
// [l,r] is a match
int z[N];
int zalgo(string & t, string& p){
	string s=p+"|"+t+"?";
	// added ? so that we do not need to compare i<n
	// z[i] contains the length of the substring starting at i that is also a suffix
	int r=0,l=0;
	for(int i=1;i<s.size()-1;i++){
		if(r<i){
			l=i,r=i-1;						// starting r from i-1 not from r!!
			while(s[r+1]==s[r-i+1]) r++;
			z[i]=r-i+1;
		}else if(z[i-l]<r-i+1) z[i]=z[i-l];	// comparing with the old
		else {
			l=i;							// note r is not adjusted here this was the key to optimization!
			// this r creates the difference in the above and this case!s
			while(s[r+1]==s[r-i+1]) r++;
			z[i]=r-i+1;
		}
	}
	int cnt=0;
	for(int i=0;i<s.size();i++) if(z[i]==p.size()) cnt++;
	return cnt;
}


int lps[N];
void kmp(string & s){
	// longest prefix which is also a suffix search
	// z algo keeps len at starting of matching substring
	// kmp keeps len at the ending of matching substring
	int len=0;
	for(int i=1;i<s.size();i++) 
		if(s[len]==s[i]) lps[i]=++len;
		else {
			while(len && s[len]!=s[i]) len=lps[len-1];
			if(s[len]==s[i]) lps[i]=++len;
		}
}

int countOccurences(string & text, string & patt){
	string s =  patt+"$"+text;
	zalgo(text,patt);
	kmp(s);
	int cnt1=0,cnt2=0;
	for(int i=0;i<s.size();i++) if(z[i]==patt.size()) cnt1++;
	for(int i=0;i<s.size();i++) if(lps[i]==patt.size()) cnt2++;
	return cnt2;
}

int main() {
	string p,t;
	cin>>p>>t;
	cout<<countOccurences(t,p);
	return 0;
}