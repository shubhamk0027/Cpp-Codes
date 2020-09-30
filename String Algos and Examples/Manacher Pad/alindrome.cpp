#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int p[N];
void manacher(string &s){
	string ss="|";
	for(auto x:s) ss.pb(x),ss.pb('|');
	ss.pb('?');
	int m=0,r=0;
	for(int i=1;i<ss.size()-1;i++){
		p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
		while(i-p[i]>=1 && ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
		if(i+p[i]>r) r=i+p[i],m=i;
	}
	// for(int i=0;i<ss.size();i++) cerr<<i<<" "; cerr<<"\n";
	// for(int i=0;i<ss.size();i++) cerr<<ss[i]<<" "; cerr<<"\n";
	// for(int i=0;i<ss.size();i++) cerr<<p[i]<<" "; cerr<<"\n";
}

// the same thing can be extended for s= sum of x palindromes!
int alindrome(string &s){
	int m1,m2,n=s.size();
	for(int len=1;len<=n;len++){
		m1=(1+2*len-1)/2;
		m2=((2*len+1)+(2*n-1))/2;
		if(p[m1]==len && p[m2]==n-len) return len;
	}
	return INT_MAX;
}

int main() {
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		manacher(s);
		int x=alindrome(s);
		if(x<s.size()) cout<<"alindrome\n";
		else if(x==s.size()) cout<<"palindrome\n";
		else cout<<"simple\n";
	}
	return 0;
}