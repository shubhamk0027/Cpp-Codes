#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define INF 1e18
#define PI 3.141592653589793238
typedef pair<ll,ll> pll;
//Classic Knapsack problem with space reduction
const ll N=1e3+1;
ll dp[100000+1];// dp[i] stores maximum value when weight of knapsack is i
void solve(){
    ll n, W; // n is no of items W is weight of knapsack
    cin >> n >> W;
    ll v[n+1]; // v is to store value of each item
    ll w[n+1]; // w is to store weight of each item
    for(ll i = 0; i < n; i++)
        cin >> w[i];


    for(ll i = 0; i < n; i++)
        cin >> v[i];


    for(ll i = 0; i < n; i++)

        for(ll j = W; j >= w[i]; j--)

            dp[j] = max(dp[j],v[i]+dp[j-w[i]]);

    cout<<dp[W];
}
signed main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
//    ll t;cin>>t;while(t--)
    solve();

}
