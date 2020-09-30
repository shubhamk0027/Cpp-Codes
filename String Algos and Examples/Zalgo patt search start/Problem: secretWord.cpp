//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3911&mosmsg=Submission+received+with+ID+23789592
// SECRET WORD, S STARTS with a substring of it reversed!
#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int z[N];
string zalgo(string &s){
	string ss=s;
	reverse(ss.begin(),ss.end());
	ss= s+"|"+ss+"?";
	int l=0,r=0,mx=0;
	for(int i=1;i<ss.size()-1;i++){
		if(r<i){
			l=i,r=i-1;
			while(ss[r+1]==ss[r-i+1]) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-l+1) z[i]=z[i-l];	
		else{
			l=i;
			while(ss[r+1]==ss[r-l+1])r++;
			z[i]=r-l+1;
		}
		if(i>s.size()) mx=max(mx,z[i]);
	}
	s=s.substr(0,mx);
	reverse(s.begin(),s.end());
	return s;
}

int main() {
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<zalgo(s)<<"\n";
	}
	return 0;
}