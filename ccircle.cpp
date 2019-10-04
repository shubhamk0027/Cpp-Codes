#include<iostream>
using namespace std;
int main(){
//n and q
int n,q;
cin>>n>>q;
int f[100000+1];
cin>>f[1]>>f[2];
int a,b;
cin>>a>>b;
//Sequence input
vector<int> sequence;
for(int i=0;i<n;i++){
int p;
cin>>p;
sequence.push_back(p);
}
//Calculating f value
for(int i=3;i<=100000;i++){
f[i]=b*f[i-1]+a*f[i-2];
}
int incrementor[100000+1]={0};
while(q--){
int l,r;
cin>>l>>r;
incrementor[l]+=f[]
}
return 0;}
