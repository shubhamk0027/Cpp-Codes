#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

string s;
struct node{
	int len,par,nxt[26];
	int pcnt;
	node(){pcnt=len=par=0; for(int i=0;i<26;i++) nxt[i]=0;}
} tr[1005];
int cnt=0,curr,ptr;

void insert(int i){
	int trav=curr;
	// FINDING LONGEST PALINDROME THROUGH PARENTS (LONGEST PLAINDROMIC SUFFIX)
	while(s[i]!=s[i-tr[trav].len-1]) trav=tr[trav].par;

	// INSERTING THE NODE IF NEEDED
	if(tr[trav].nxt[s[i]-'a']){
		curr=tr[trav].nxt[s[i]-'a'];
		cnt+=tr[trav].pcnt;
		return ;
	}
	tr[trav].nxt[s[i]-'a']=++ptr;
	tr[ptr].len=tr[trav].len+2;

	// FINDING PARENT OF THIS NEW NODE
	curr=ptr;
	if(tr[ptr].len==1) {
		tr[ptr].par=2;
		cnt+=(tr[ptr].pcnt=1);
		return ;
	}

	trav=tr[trav].par;
	while(s[i]!=s[i-tr[trav].len-1]) trav=tr[trav].par;

	tr[ptr].par=tr[trav].nxt[s[i]-'a'];
	cnt+=(tr[ptr].pcnt=tr[tr[ptr].par].pcnt+1);
}

void build(){
	curr=1;ptr=2;
	tr[1].len=-1;
	tr[2].len=0;
	tr[1].par=tr[2].par=1;
	for(int i=0;i<s.size();i++) insert(i);
}

int main() {
	cin>>s;
	build();
	cout<<cnt;
	return 0;
}