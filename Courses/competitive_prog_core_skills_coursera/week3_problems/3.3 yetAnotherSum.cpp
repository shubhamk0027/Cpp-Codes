#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while(cin>>n)
    {
        ll dec=0;
        double frac=0.0;
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            dec+=arr[i];
            frac+=1.0/(arr[i]*1.0);
        }
        double ans=(double)dec+frac;
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
}
