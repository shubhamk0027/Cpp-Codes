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
    string s;
    cin >> s;
    ll ans = 0;
    ll last = 0;
    ll sign = 1;

    for (ll i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '+' || c == '-') {
            ans += sign * last;
            last = 0;
            if (c == '+') {
                sign = 1;
            } else {
                sign = -1;
            }
        } else {
            last = 10 * last + (c - '0');
        }
    }

    ans += sign * last;
    cout << ans << '\n';

    return 0;
}
