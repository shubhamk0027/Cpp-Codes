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
ll lookup[1000][1000];
ll solve(ll len,ll sum)
{
    if(len==0)
        return sum==0;
    if(lookup[len][sum]!=-1)return lookup[len][sum];
    ll ans=0;
    for(ll i=0;i<=9;i++)
        if(sum-i>=0)
        ans+=solve(len-1,sum-i);
    return lookup[len][sum]=ans;
}
int main()
{
    /*
for reading from input.txt and writing on output.txt
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
    ll sum,len;
    while(cin>>sum>>len)
    {
        if(sum==0 && len==1)
        {
            cout<<1<<endl;
            continue;
        }
        ll ans=0;
        memset(lookup,-1,sizeof(lookup));
        for(ll i=1;i<=9;i++)
        {
            if(sum-i>=0)
            {
                ans+=solve(len-1,sum-i);
            }
        }
        cout<<ans<<endl;
    }
}

