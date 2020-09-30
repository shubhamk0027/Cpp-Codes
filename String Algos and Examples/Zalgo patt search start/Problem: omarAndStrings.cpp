#include<bits/stdc++.h>
#define ll int64_t
#define pb push_back

using namespace std;
const ll mod =1e9+7;
const int N =1e6+5;

int ar[N];
struct bit{
	int query(int x){
		ll res=0; 
		while(x) res+=ar[x],x-=(x&-x);
		return res;
	}
	void upd(int x,int by){ while(x<N) ar[x]+=by, x+=(x&-x); }
} bb;


int z[N];
void zalgo(string &s){
	// z[i]-> length of the suffix starting at pos i
	string ss= s+"?";
	int r=0,l=0,n=ss.size();
	for(int i=1;i<n-1;i++){
		if(r<i){
			l=i,r=i-1;						// starting r from i-1 not from r!!
			while(ss[r+1]==ss[r-l+1]) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-i+1) z[i]=z[i-l];	
		else {
			l=i;							// no need to readjust r, this helps in optimization!
			while(ss[r+1]==ss[r-l+1]) r++;
			z[i]=r-l+1;
		}
	}
	for(int i=1;i<n;i++) if(z[i]) bb.upd(z[i]+1,-1), bb.upd(1,1);
}

int p[N];
string manacher(string &s){
	// manacher-> longest pad with center i
	string ss= "|";
	for(auto x: s) ss.pb(x),ss.pb('|');
	int r=0,m=0,n=ss.size();
	for(int i=1;i<n-1;i++){
		if(i<r) p[i]=min(r-i,p[m-(i-m)]);
		while(i-p[i]>=1 && ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
		if(i+p[i]>r) r=i+p[i],m=i;	
	}
	int st=0,ed=-1;
	for(int i=1;i<ss.size();i++){
		if(i==p[i]) st=i;
		if(ed==-1 && i+p[i]==ss.size()-1) ed=i;
	}
	string res= s.substr((ed-p[ed]+1)/2,p[ed])+ s.substr((st-p[st]-1)/2,p[st]);
	return res;
}

int main() {
	cin.tie(NULL); 
	cout.tie(NULL); 
	ios_base::sync_with_stdio(false);
	
	string s,res;
	cin>>s;
	res=manacher(s);
	cout<<res<<"\n";
	zalgo(res);
	
	for(int i=0;i<res.size();i++) cout<<bb.query(i+1)+1<<" ";
	return 0;
}