#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <sstream>
#include <iomanip>
using namespace std;


#define int int64_t
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define vii vector< vector<int> >
#define ff first
#define ss second
#define pii pair<int64_t, int64_t>
#define mp make_pair
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int> >
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x) int x; cin>>x; while(x--)
#define FIO  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int dp[1000][1000]={-1};
vii dp(1000,vi(1000, -1));
int ans(const vector<pii> v, int n, int w)
{
    if(n==0 or w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    else
    {
        if(n >= v[n-1].ff)
            dp[n][w] = max(ans(v,n-1,w), ans(v, n-1, w - v[n-1].ff)+v[n-1].ss);
        
        else
            dp[n][w] = ans(v,n-1,w);
        
        return dp[n][w];
    }
    
}


int32_t main()
{
    int i, n, j, w, k, l, t;
    cin >> n >> w;
    vector<pii> v(n);
    f(i,n) cin >> v[i].ff >> v[i].ss ;
    cout << ans(v, n, w);

}