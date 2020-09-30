#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N =1e5+1;

string s;
int n;

namespace SA{
	int sa[N],val[N],tmp[N],k;
	bool comp(int i, int j){
		if(val[i]!=val[j]) return val[i]<val[j];
		return (i+k<n && j+k<n)?val[i+k]<val[j+k]:i>j;
		return val[(i+k)%n]<val[(j+k)%n];

	}
	int build(){
		for(int i=0;i<n;i++) sa[i]=i,val[i]=s[i];
		for(k=1;k<n;k<<=1){
			stable_sort(sa,sa+n,comp);
			for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+comp(sa[i-1],sa[i]);
			for(int i=0;i<n;i++) val[sa[i]]=tmp[i];
			if(tmp[n-1]==n-1) break;
		}
		return sa[0];
	}
}

int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		cout<<SA::build()<<"\n";
	}
	return 0;
}