#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

int n,cnt;
string s;

// palindromic tree with all the distinct padic substrings of the given strings.
struct node{
	int len,par,l,r;
	int nxt[26];
	int pCount;
	// parent node is the longest suffix node that is also a palindrome
	// and will help in checking pad of len 2l to 2l-2 to 2l-3... till -1 len
} tr[N];
int curr,ptr;
// ptr will be used only when we want to have a new node

// First we build up the basic strings (called the root of len)
// -1 -> 	root 1
// 0 -> 	root 2
// 1 -> 	root ..
// for each i we traverse trough the suff edges and find a suitable placement for 
// 	the substring ending at index i
// also we add a suffix edge to find the longest pad which is also a suffix 

bool insert(int i){
	int trav=curr,len;
	// FIND THE PARENT PALINDROME EDGE
	while(1){
		len=tr[trav].len;
		if(i-len>=1 && s[i]==s[i-len-1]) break;
		trav=tr[trav].par;
	}
	// ADD THE NEW PALINDROME NODE
	if(tr[trav].nxt[s[i]-'a']) {
		curr=tr[trav].nxt[s[i]-'a'];
		cnt+=tr[trav].pCount;
		return false;
	}
	// cerr<<"Adding Insertion edge"<<trav<<"->"<< ptr+1<<"\n";
	tr[trav].nxt[s[i]-'a']=++ptr;
	tr[ptr].len=tr[trav].len+2;
	tr[ptr].r=i;
	tr[ptr].l=i-tr[ptr].len+1;
	
	// FIND ITS PARENT
	curr=ptr;	
	if(tr[ptr].len==1){
		// cerr<<"Adding Suffix edge"<<ptr<<"->"<< 2<<"\n";
		tr[ptr].par=2;
		cnt+=++tr[ptr].pCount;
		return 1;
	}
	trav=tr[trav].par;
	while(1){
		len=tr[trav].len;
		if(i-len>=1 && s[i]==s[i-len-1]) break;
		trav=tr[trav].par;
	}
	tr[ptr].par=tr[trav].nxt[s[i]-'a'];
	cnt+=(tr[ptr].pCount=tr[tr[ptr].par].pCount+1);
	// cerr<<"Adding Suffix edge"<<ptr<<"->"<<tr[ptr].par<<"\n";
	return 1;
}

void build(){
	curr=1,ptr=2;
	tr[1].len=-1;			// for forming pads of len 1
	tr[1].par=1;			// edge 1 pointing to itself
	tr[2].len=0;			// for forming pads of len 2
	tr[2].par=1;			// edge 2 pointing to 1
	for(int i=0;i<s.size();i++) insert(i); 
}

int main() {
	s="abcbab";
	build();
	
	cout<<"All distinct pads:";
	for(int i=2;i<=ptr;i++,cerr<<"\n") 
		for(int j=tr[i].l;j<=tr[i].r;j++) 
			cerr<<s[j];

	cerr<<"# All Plaindromes Possible: "<<cnt<<"\n";	
	cerr<<"# Distinct Plaindromes Possible: "<<ptr-2<<"\n";	
	cerr<<"# Distinct Plaindromes Possible: "<<ptr-2<<"\n";	
	return 0;
}

// TIME COMPLEXIITY->
// O(N*K) where is the extra iterations per i