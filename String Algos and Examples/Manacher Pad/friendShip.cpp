// https://csacademy.com/contest/archive/task/palindromic-friendship/
// WA In two cases!
// Other ways->
// sort by diff between the pairs
// and then add the pair and count the numbers in range p.first and p.second in a set

#include<bits/stdc++.h>
using namespace std;

const int N =5e5+10;
int n,m;
int p[N];

int get(int x){
	if(x==p[x]) return x;
	return p[x]=get(p[x]);
}

void join (int x, int y){
	x=get(x),y=get(y);
	p[x]=y;
}

int manacher(){
	vector<int> ss={0};
	for(int i=1;i<=n;i++) ss.push_back(get(i)),ss.push_back(0);
	int m=0,r=0,mx=0;
	for(int i=1;i<ss.size()-1;i++){
		p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
		while(i-p[i]>=1 && ss[i+1+p[i]]==ss[i-1-p[i]]) p[i]++;
		if(i+p[i]>r) m=i,r=p[i]+i;
		mx=max(mx,p[i]);
	}
	return mx;
}

int main() {
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=0;i<m;i++)  cin>>x>>y,join(x,y);
	cout<<manacher();
	return 0;
}