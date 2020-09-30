#include<bits/stdc++.h>
using namespace std;
const long long mod=109546051211;
const long long base=10000000; 

long long prod(long long a, long long b){
    long long a1 = a/base,a2=a%base;
    long long b1 = b/base,b2=b%base;
    long long res = (((((a1*b1)%mod)*base)%mod)*base)%mod;
    res = res + (((a1*b2)%mod)*base)%mod +(((a2*b1)%mod)*base) + (a2*b2)%mod;
    return res%mod;
}

int main(){
    long long n,res=1,fact=1;
    //NOTE HERE MOD IS OF 12 DIGITS MULTIPLICATION WILL MAKE IT OVERFLOW!!!
    cin>>n;
    for(int i=1; i<=n;i++) fact=prod(fact,i), res=prod(res,fact);
    cout<<res;
    return 0;
}