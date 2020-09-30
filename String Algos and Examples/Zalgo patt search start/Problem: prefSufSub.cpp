#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

string s;
int z[N],n,len;
void zalgo(){
	n=s.size();
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(r<i){
			l=i,r=i-1;
			while(s[r+1]==s[r-l+1] && r+1<n) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-i+1) z[i]=z[i-l];
		else{
			l=i;
			while(r+1<n && s[r+1]==s[r-l+1]) r++;
			z[i]=r-l+1;
		}
		if(r==n-1) len=max(len,z[i]-1);
		else len=max(len,z[i]);
	}
	// find a string that is a suffix as well as prefix as well as a substring of maximum length possible!
}

int main() {
	cin>>s;
	zalgo();
	int fin=0;
	for(int i=0;i<n;i++) if(z[i]+i==n){
		if(z[i]<=len) fin=max(fin,z[i]);
	}
	if(!fin) cout<<"Just a legend";
	else cout<<s.substr(0,fin);
	return 0;
}