#include<bits/stdc++.h>
#define ll int64_t
#define pb push_back
#define vi vector<int>

using namespace std;
const int N =1e6+10;


string s;
struct node{
	ll res;
	bool leaf;
	int len,par,sum,r,ch[10];
	node(){for(int i=0;i<10;i++) ch[i]=0;len=sum=leaf=res=0;}
};
// the untlimate code orgasmmmmm...
// we modified the way it was used to find the number of palindromes
// 1111 has 111 as parent but derived from 11
// so the sum and len is derieved from 11 
// but result is derived from 111

node pt[N];
int ptr=2,curr=1;
ll tot=0;

void add(int i){
    // curr is the node where the current char ends and so wil change at every insertion!!
	// ptr will be used only and only when we want to create a new node
	int trav=curr;
	// find the correct parent to derive from
	while(s[i]!=s[i-pt[trav].len-1]) trav=pt[trav].par; // -1 not +1
	if(pt[trav].ch[s[i]-'0']) curr=pt[trav].ch[s[i]-'0'];	
	// val is already there no need to compute!
	else{
        // create new cc
		// these values are derived from trav node only
		curr=++ptr;
		pt[trav].ch[s[i]-'0']=curr;
		pt[curr].r=i;
		if(pt[curr].len==1) {
			pt[curr].par=2;
			pt[curr].sum=s[i]-'0';
			pt[curr].leaf=0; // never be a leaf node!
		}else{
            pt[curr].sum=pt[trav].sum+2*(s[i]-'0');
            pt[curr].len=pt[trav].len+2;
			pt[curr].leaf=(s[i]=='0');
			trav=pt[trav].par;
			while(s[i]!=s[i-pt[trav].len-1]) trav=pt[trav].par;
			pt[curr].par=pt[trav].ch[s[i]-'0'];
		}
		// the finally calculating res is derived from this parent!
		pt[curr].res=pt[pt[curr].par].res;
		if(!pt[curr].leaf) pt[curr].res+=((pt[curr].sum%3)==0);
	}
	// add the result finally!
	tot+=pt[curr].res; 	
}

void build(){
	pt[1].len=-1; pt[1].par=1;
	pt[2].len=0; pt[2].par=1;
	for(int i=0;i<s.size();i++) add(i);
}

int main() {
	cin>>s;
	build();
	cout<<tot;
	return 0;
}