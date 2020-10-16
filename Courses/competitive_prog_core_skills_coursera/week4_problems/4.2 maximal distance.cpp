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
    map<ll,ll> m;
    ll n,x;cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>x;
        m[x]=i;
        auto it=m.begin();
        cout<<(*it).second<<" ";
        it=m.end();it--;
        cout<<(*it).second<<endl;
    }
}
