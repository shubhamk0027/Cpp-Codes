#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int lps[202];
int kmp(string &a, string &b){
	string ss= b+"$"+a;
	int len=0;
	for(int i=1;i<ss.size();i++){
		while(len && ss[i]!=ss[len]) len=lps[len-1];
		if(ss[i]==ss[len]) lps[i]=++len;
		else lps[i]=len=0;
	}
	return len;
}


int main() {
	int t,n,k;
	cin>>t;
	while(t--){
		string a,b;
		cin>>k>>n;
		int res=k;
		cin>>a;
		for(int i=1;i<n;i++) {
			cin>>b;
			res=res+k-kmp(a,b);
			a=b;
		}
		cout<<res<<"\n";
	}

	return 0;
}