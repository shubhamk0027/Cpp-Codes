#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;

class SureThing{
    public:
    map<vector<int>,double> dp;

    // [100,100,100,100,100]
    double solve(vi v){
        sort(v.rbegin(),v.rend());
        if(v.size()==1 || v[1]==0) return pow(2.0,v[0]);
        if(dp.find(v)!=dp.end()) return dp[v];
        // Only few states are called not all!
        v[0]--; double a0 = solve(v); v[0]++;
        v[1]--; double a1 = solve(v); v[1]++;
        double x= (a1-a0)/(a1+a0);
        x=(1-x)*a1;
        return dp[v]=x;
    }

    double ans(vi v){
        double x= solve(v);
        cerr<<dp.size()<<"\n";
        return x;
    }
};

// This proves that there are about 1e9 states possible!
// but since we will do pruning only few states will be covered!

int dp[6][100];
class Just{
    public:
    int solve(int n, int x){
        if(x==0) return 1;
        if(n==1) return x+1;
        int res=0;
        if(dp[n][x]!=0) return dp[n][x];
        for(int i=1;i<=x;i++)
            res+=solve(n-1,x-i);
        return dp[n][x]=res;
    }
};

int main(){
    SureThing s;
    // printf("%.10lf",s.ans(	{100, 100, 100, 100, 100, 100}));
    Just j;
    cout<<j.solve(2,100);
    return 0;
}