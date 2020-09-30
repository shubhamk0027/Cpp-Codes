#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N =1e7+1;

int n;
string s;
namespace SA{
	int gap;
	int sa[N],val[N],tmp[N],lcp[N];
	bool comp(int i, int j){
		if(val[i]!=val[j]) return val[i]<val[j];
		return (i+gap<n && j+gap<n)?val[i+gap]<val[j+gap]:i>j;
	}
	void build(){
		n=s.size();
		for(int i=0;i<n;i++) sa[i]=i,val[i]=s[i];
		for(gap=1;gap<n;gap<<=1){
			sort(sa,sa+n,comp);
			for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+comp(sa[i-1],sa[i]);
			for(int i=0;i<n;i++) val[sa[i]]=tmp[i];
			if(tmp[n-1]==n-1) break;
		}
	}
	int LCP(){
		build();
		int k=0,mx;
		for(int i=0;i<n;i++) val[sa[i]]=i;
		for(int i=0;i<n;i++){
			if(val[i]<n-1){
				int j=sa[val[i]+1];
				while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
			}else k=0;
			lcp[val[i]]=k;
			mx=max(mx,k);
			if(k) k--;
		}	
		return mx;
	}
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>s;
		n=s.size();
		cout<<SA::LCP()<<"\n";
	}
	return 0;
}
