#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

string s;
int z[N],n;

string zalgo(){
	// when i did this question in the first time it was AC in one go
	// now it is not why?
	// thought i did this earlier and tried to use the same algo without thinking actually!
	// was not able to point out the logic clearly this time
	int r=0,l=0,len=0;
	s.pb('#');
	for(int i=1;i<n;i++){
		if(r<i){
			l=i,r=i-1;
			while(s[r+1]==s[r-l+1]) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-l+1) z[i]=z[i-l];
		else {
			l=i;
			while(s[r+1]==s[r-l+1]) r++;
			z[i]=r-l+1;
		}
		if(r==n-1) len=max(len,z[i]-1);
		else len=max(len,z[i]);
	}
	int m=0;
	for(int i=0;i<n;i++) if(z[i]+i==n && z[i]<=len) m=max(m,z[i]);  
	if(m) return s.substr(0,m);
	else return "Just a legend";
}

int main() {
	cin>>s;
	n=s.size();
	cout<<zalgo();
	return 0;
}