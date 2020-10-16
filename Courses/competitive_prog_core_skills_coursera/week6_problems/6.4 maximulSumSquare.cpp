#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
#include <deque>
#include <map>
#include <deque>
#include <iomanip>
#include <cmath>
#include <functional>
#include <set>
#include <list>
#define endl '\n'
#define FOR(i,a,n,c) for(int i=a;i<=n;i+=c)
using namespace std;
#define MOD 1000000007
#define ll long long
#define pb push_back
typedef pair<ll,ll> pll;
int main()
{
    /*
for reading from input.txt and writing on output.txt
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
    ll n,k;
    while(cin>>n>>k)
    {
        ll arr[n+1][n+1];
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
            cin>>arr[i][j];
        ll sum[n+1][n+1];
        memset(sum,0,sizeof(sum));
        sum[1][1]=arr[1][1];
        for(ll i=2;i<=n;i++)
            sum[1][i]=sum[1][i-1]+arr[1][i];
        for(ll i=2;i<=n;i++)
            sum[i][1]=sum[i-1][1]+arr[i][1];
        for(ll i=2;i<=n;i++)
            for(ll j=2;j<=n;j++)
                sum[i][j]=arr[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                if(i-k>=0 && j-k>=0)
                {
                    ll tempSum=sum[i][j] - sum[i][j-k] - sum[i-k][j] + sum[i-k][j-k];
                    ans=max(ans,tempSum);
                }
            }
        }
        cout<<ans<<endl;
    }
}

