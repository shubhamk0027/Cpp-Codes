#include<bits/stdc++.h>
using namespace std;

int maxmod(int n, int k){
    int mx = 0;
    while (k >mx+1 && k>4.0*sqrt(n)){
        mx=max(mx, n % k);
        k = min(k - 1, 1 + n / (1 + n / k));
    }
    for (; k > mx + 1; --k)  {
        mx = max(mx, n % k);
    }
    return mx;
}
	
int main(){
	int n,p;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>p;

    int m = maxmod(n,p);
    // if(p>=n) m = maxmod(n,n);
    // else m = maxmod(n,p);
    cout<<m;

    return 0;
}
