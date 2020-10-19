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

int32_t main()
{
    int n, W, i, j; cin >> n >> W;
    vi val(n), wt(n);
    f(i,n) cin >> val[i];
    f(i,n) cin >> wt[i];
    
//    int i, j;
     vector<int> dp(W+1,0), cur_dp(W+1,0);
    

    bool k=true;
    for(i=1;i<n+1;i++)
    {
        for(j=W;j>=0;j--)
        {
            if(k)
            {
                if(wt[i-1]<j)
                    cur_dp[j] = max(cur_dp[j-1], dp[j-wt[i-1]]+val[i-1]); 
                    
                else cur_dp[j] = cur_dp[j-1];
                
            }
            
            else
            {
                if(wt[i-1]<j)
                    dp[j] = max(dp[j-1], cur_dp[j-wt[i-1]]+val[i-1]); 
                    
                else dp[j] = dp[j-1];
                
            }
        }
        
        k^=1;
    }

     if(k) 
    {
        int temp=INT_MIN;
        for(i=0;i<W+1;i++) temp = max(temp, dp[i]);
        cout <<  temp;
    }
    else 
    {int temp=INT_MIN;
        for(i=0;i<W+1;i++) temp = max(temp, cur_dp[i]);
        
        cout <<  temp;
        
    }

}