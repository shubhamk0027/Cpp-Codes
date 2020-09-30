#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod =1e9+7;
const int RMAX =100; // MAXIMUM VALUE OF THE REMAINDER POSSIBLE
const int DMAX =15;  // MAXIMUM NUMBER OF DIGITS POSSIBLE;
int dp[DMAX][2][RMAX];
string s;
ll k;

// COMPLEXITY IS REDUCED TO O(N*K)
// else it would have been N^k
ll solve(int id, bool smaller, int rem){
    if(id==s.size())                     // BASE CASE
    if(rem==0) return 1; else return 0;  // DOES IT SATISFIES THE PROPERTY?
    if(dp[id][smaller][rem]!=-1) return dp[id][smaller][rem];
    ll res=0;
    int limit = 9;
    if(smaller) limit= s[id]-'0';
    for(int i=0; i<=limit;i++){
        bool isSmaller=smaller;
        if(i<s[id]-'0') isSmaller=0;
        res+=solve(id+1,isSmaller,(rem+i)%k);
    }
    return dp[id][smaller][rem]=res;
}


int main(){
    ll a,b;
    cin>>a>>b>>k;
    memset(dp,-1,sizeof dp);
    s= to_string(a-1);
    ll res= solve(0,1,0);
    memset(dp,-1,sizeof dp);
    s= to_string(b);
    res = solve(0,1,0)-res;
    cout<<res<<"\n";
    return 0;
}