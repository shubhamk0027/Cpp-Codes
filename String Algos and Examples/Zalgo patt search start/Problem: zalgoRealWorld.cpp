// w[] pattern wall
// ar[] given wall, find number of places where the shape of w exactly matches the shape in w 
#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =5e5+1;

ll ar[N],ss[N],n,w,z[N];
int zalgo(){
	int l=0,r=0,d=0,cnt=0;
	for(int i=0;i<=n+w;i++){
		if(r<i){
			l=i,d=ss[i]-ss[0];
			r=i-1;
			while(r+1<n+w+1 && ss[r-l+1]+d==ss[r+1]) r++;
			z[i]=r-l+1;
		}else if(z[i-l]<r-i+1) z[i]=z[i-l];
		else{
			l=i,d=ss[i]-ss[0];
			while(r+1<n+w+1 && ss[r-l+1]+d==ss[r+1]) r++;
			z[i]=r-l+1;
		}
		if(i>w && z[i]==w) cnt++;
	}
	return cnt;
}

int main() {
	cin>>n>>w;
	for(int i=0;i<n;i++) cin>>ar[i];
	for(int i=0;i<w;i++) cin>>ss[i];
	ss[w]=INT32_MAX;
	for(int i=0;i<n;i++) ss[i+w+1]=ar[i];
	cout<<zalgo();	
	return 0;
}