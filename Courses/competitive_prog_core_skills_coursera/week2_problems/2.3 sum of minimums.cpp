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
using namespace std;
#define MOD 1000000007
#define ll long long
#define pb push_back
typedef pair<ll,ll> pll;
int main(){
cin.sync_with_stdio(false);
    ll n;
    while(cin>>n)
    {
        ll arr[n+1];
        for(ll i=1;i<=n;i++)cin>>arr[i];
        ll sum=0;
        for(ll i=1;i<=n;i++)
        {
            ll temp=arr[i];
            for(ll j=i;j<=n;j++)
            {
                temp=min(temp,arr[j]);
                sum+=temp;
            }
        }
        cout<<sum<<endl;
    }
}
