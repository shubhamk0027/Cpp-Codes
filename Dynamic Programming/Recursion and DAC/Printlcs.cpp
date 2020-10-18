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
#define vb vector<bool>
#define vbb vector< vector<bool> >
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
    FIO;
    int i, m, n, j, k, l, t;
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    vii dp(n+1, vi(m+1,0));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1]) 
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    f(i,n+1)
    {
        f(j,m+1) cout << dp[i][j] << " ";
        cout << endl;
    }
    i=n, j=m;
    stack<char> s;

    while(i and j)
    {
        if(s1[i-1]==s2[j-1]) 
        {
            s.push(s1[i-1]);
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--; 
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}