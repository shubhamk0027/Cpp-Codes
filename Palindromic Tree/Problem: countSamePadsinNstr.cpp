// given n strings, count the number of ways to get identical substring palindromes
// from all the n strings.
#include<bits/stdc++.h>
#define ll int64_t
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N=2e6+1;

void EE(int aa, int bb, int& xx, int& yy){if(aa%bb == 0){xx=0,yy=1;return;}
EE(bb,aa%bb,xx,yy);int t = xx;xx = yy;yy = t - yy*(aa/bb);}
int mmi(int aa){int xx,yy;EE(aa,mod,xx,yy);xx = (xx+mod)%mod;return xx;}

ll res,deno=1;
int n,ptr,curr,id;
int len[N],p[N],ch[N][26],lazy[N];	
// common cnt, new vis for each string and new lazy for each string!
vi cnt[N],vis;
string s;

void add(int i){
	int trav=curr;
	while(s[i-len[trav]-1]!=s[i]) trav=p[trav];
	if(ch[trav][s[i]-'a']){
		curr=ch[trav][s[i]-'a'];
	}else{
		curr=++ptr;
		ch[trav][s[i]-'a']=curr;
		len[curr]=len[trav]+2;
		if(len[ptr]==1)	p[ptr]=2;
		else {
			trav=p[trav];
			while(s[i-len[trav]-1]!=s[i]) trav=p[trav];
			p[curr]=ch[trav][s[i]-'a'];
		}
	}
	// dont forget to update the child of the parent in both the cases
	// update in the end
	// curr will change at every iteration!
	// ptr will be used only at the time of adding a new node
	// lazy will be updated at the end to count the number of occurences of each palindrome
	lazy[curr]++;
	vis.pb(curr);
}

// Instead of finding n paindrome trees we will append the changes in the same palindrome tree
// but the value[] vector will change every time we create a new pd tree, though the last nodes remains the same
void update(){
	sort(vis.begin(),vis.end());
	vis.resize(distance(vis.begin(),unique(vis.begin(),vis.end())));
	for(int i=vis.size()-1;i>=0;i--) {
		lazy[p[vis[i]]]+=lazy[vis[i]];
		cnt[vis[i]].pb(lazy[vis[i]]);
		lazy[vis[i]]=0;
	}
}

void build(){
	ptr=2;
	len[1]=-1,p[1]=1;
	len[2]=0,p[2]=1;
	for(id=0;id<n;id++){
		cin>>s;
		vis.clear();
		curr=1;
		for(int i=0;i<s.size();i++) add(i);
		update();
		ll x=s.size();
		x=((x*(x+1))/2)%mod;
		deno=(deno*x)%mod;
	}
	for(int i=0;i<N;i++) if(cnt[i].size()==n){
		ll temp=1;
		for(auto c:cnt[i]) 
		temp=(temp*c)%mod;
		res=(res+temp)%mod;
	}
}

int main() {
	cin>>n;
	build();
	res=(res*mmi(deno))%mod;
	cout<<res;
	return 0;
}
