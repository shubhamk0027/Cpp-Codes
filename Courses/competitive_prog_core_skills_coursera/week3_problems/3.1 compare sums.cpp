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
double a[100], b[100];
void read_vector(ll n){
	double x;
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < n; ++i)
        cin >> b[i];
}
void print_vector(ll n){
    for (ll i = 0; i < n; ++i){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for (ll i = 0; i < n; ++i){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}
void print_result(double x,double y,double error){
	if (abs(x-y)<error)
        cout << "SUM(A)=SUM(B)" << "\n";
    else if (x>y+error)
        cout << "SUM(A)>SUM(B)" << "\n";
    else
        cout << "SUM(A)<SUM(B)" << "\n";
}
int main(){
	cin.sync_with_stdio(false);
    double sum_a;
    double sum_b;
    ll n;
    double error;
    while(cin >> n){
        read_vector(n);
    //  print_vector(n);
        sum_a = accumulate(a,a+n,0.0);
        sum_b = accumulate(b,b+n,0.0);
        error = (double)n/(200000.0);
        print_result(sum_a,sum_b,error);
    }
    return 0;
}
