#include<bits/stdc++.h>
#define ll int64_t
#define pb push_back

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

// struct node{
// 	int p,cnt,sum;
// 	node(){p=cnt=sum=0;};
// } p[N];
// THREE CASES
// when r>i simple expanding;(CASE 1)
// when i<r and
//			CASE 2
//			p[m-(i-m)]<=r-i, adjust p values to the old values of the p[m-(i-m)] and expand
//	 			org: 	|0|3|0|6(m)|0|0|0|0|0|0(r)|
//	 			final: 	|0|3|0|6(m)|0|3|0|0|0|0(r)|
// 			CASE 3
//			p[m-(i-m)]> r-i, adjust values of p from the old mid point values
//	 			org: 	|0|3|0|6(m)|0|0|0|0|0|0(r)|0|0|0   |
//	 			final: 	|0|3|0|6(m)|0|9|0|0|0|0   |0|0|0(r)|
// So state save will not work here as case 3 would be difficult
// INSTEAD -> CONSIDER f(i,k) =  s[i-k]..+s[i-1]+s[i]+s[i+1]+...s[i+k]
// 					f(i,k)%3==0 if(s[i]%3==3-2*(s[i+1]+...s[i+k]))%3
// + we also have to take the case when the last nums are not 0, for this we will maintain another r'
// and r'=r if(s[r/2]==0)
// and this r' will be the k!
// More better this could have been tacked in the precomputation itself!!! dont inc count if si=0


string s,ss;
int p[N],cnt[3][N],pf[N];

void precompute(){	
	ss="|"; 
	for(auto x:s) ss.pb(x),ss.pb('|');
	ss.pb('?');
	for(int i=1;i<ss.size();i++){
		cnt[0][i]=cnt[0][i-1],cnt[1][i]=cnt[1][i-1],cnt[2][i]=cnt[2][i-1];
		pf[i]=pf[i-1];
		if(ss[i]>='0' && ss[i]<='9') {
			pf[i]=(pf[i]+2*(ss[i]-'0'))%3;
			if(ss[i]!='0') cnt[pf[i]%3][i]++; 
		}
	}
}

void manacher(){
	int m=0,r=0;
	for(int i=1;i<ss.size();i++){
		if(i<r){
			if(p[m-(i-m)]<=r-i) p[i]=p[m-(i-m)];
			else p[i]=r-i;
		}
		while(i-p[i]>=1 && ss[i-p[i]-1]==ss[i+p[i]+1]) p[i]++;
		if(i+p[i]>r) r=p[i]+i,m=i;
	}
}

ll solve(){
	ll tot=0;
	// check (x+2(z))%3=0=> (3-x)=(2z)%3
	for(int i=1;i<ss.size()-1;i++){
		int cc=0;						// if even len check for x=0
		if(ss[i]<='9' && ss[i]>='0')  {
			// for the digits belonging to this range simply add 1 if it is div
			cc=(ss[i]-'0')%3;
			tot+=((ss[i]-'0')%3==0);
		} 
		cc=3-cc;						// (x+2z)%3=0 => 2z%3 = 3-x
		cc= (cc+pf[i])%3;				// relative to pf[i]
		tot+=(cnt[cc][i+p[i]]-cnt[cc][i]);
	}
	return tot;
}

int main() {
	cin>>s;
	precompute();
	manacher();
	cout<<solve();
	return 0;
}