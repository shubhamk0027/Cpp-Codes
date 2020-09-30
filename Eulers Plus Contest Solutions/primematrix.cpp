#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

vi primes;
const int N=100010;
void build_seive(){
    vi res;
    vector<bool> isp(N,1);
    int to =sqrt(N);
    for(int j=4;j<N;j+=2) isp[j]=0;
    for(int i=3;i<=to;i+=2){
        if(!isp[i]) continue;
        for(int j=i+i;j<N;j+=i) isp[j]=0;
    }
    for(int i=2;i<N;i++) if(isp[i])res.push_back(i);
    primes=res;
}

main(){
    build_seive();
    int n,m;
    cin>>n>>m;
    vector< vi > vec(n,vi(m));
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++)
            cin>>vec[i][j];
    }
    int best=N,curr;
    // OR instead of finding a lower bound each time we can simply do
    // for(i=100500;i>1;i--)
    // if(p[i]==0)
    // b[i]=0; 
    // else 
    // b[i]=b[i+1]+1;
    for(int i=0; i<n;i++){
        curr=0;
        for(int j=0; j<m;j++) 
        curr = curr + primes[lower_bound(primes.begin(),primes.end(),vec[i][j])-primes.begin()]- vec[i][j];
        if(curr<best) best=curr;
    }
    for(int i=0; i<m;i++){
        curr=0;
        for(int j=0; j<n;j++)
        curr = curr + primes[lower_bound(primes.begin(),primes.end(),vec[j][i])-primes.begin()] -vec[j][i];
        if(curr<best) best=curr;
    }
    cout<<best;
}