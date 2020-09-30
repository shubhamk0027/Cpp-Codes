#include<bits/stdc++.h>
using namespace std;
const int N =2e6+1;

string s;
int n,gap;
int sa[N],val[N],tmp[N],lcp[N];

bool comp(int i, int j){
	if(val[i]!=val[j]) return val[i]<val[j];
	return (i+gap<n && j+gap<n)?val[i+gap]<val[j+gap]:i>j;
}

void SA(){
	n=s.size();
	for(int i=0;i<n;i++) sa[i]=i,val[i]=s[i];
	for(gap=1;gap<n;gap<<=1){
		sort(sa,sa+n,comp);
		for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+comp(sa[i-1],sa[i]);
		for(int i=0;i<n;i++) val[sa[i]]=tmp[i];
		if(tmp[n-1]==n-1) break;
	}
	for(int i=0;i<n;i++) cerr<<sa[i]<<" ";
}


// THINGS TO CONSIDER->
// a substring is denoted by a no x = substr(x..n)
// sa[i] = 	substr at rank i
// rank[i]= rank of the substr i

// Id->	{0,		1,		2,			3,			4,		5		}
// SA-> {5(a),	3(ana),	1(anana),	0(banana),	4(na),	2(nana) }
// RA-> {3		2		5			1			4		0		}
// if sa[i], and sa[i+1] have k len in common then sa[i+1] && sa[i+2] will have atleast k in common or 0

void LCP(){
	int* const &rank =tmp;
	for(int i=0;i<n;i++) rank[sa[i]]=i;	// Rank of substr(i)
	int k=0;
	// for substr(i)->
	// get the rank of this substr
	// get the (rank+1)st smallest substr		
	for(int i=0;i<n;i++){			
		if(rank[i]==n-1) {k=0;continue;}
		int j=sa[rank[i]+1];				
		while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
		lcp[rank[i]]=k;
		if(k) k--;
	}
}

void print(){
	cerr<<"SA:\t"<<" "; for(int i=0;i<n;i++) cerr<<sa[i]<<" "; 
	cerr<<"\nRnk\t"<<" "; for(int i=0;i<n;i++) cerr<<tmp[i]<<" ";
	cerr<<"\nlcp\t"<<" "; for(int i=0;i<n;i++) cerr<<lcp[i]<<" ";
}

int main() {
	// s="banana";
	string t;
	cin>>s>>t;
	s=s+"$"+t;
	SA();
	// LCP();
	// print();
	return 0;
}
	