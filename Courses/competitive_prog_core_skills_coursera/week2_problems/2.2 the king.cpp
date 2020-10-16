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
    ll r,c;
    while(cin>>r>>c)
    {
        ll tot=r*c;
        ll king=ceil(r*1.0/3.0)*ceil(c*1.0/3.0);
        cout<<tot-king<<endl;
    }
}
