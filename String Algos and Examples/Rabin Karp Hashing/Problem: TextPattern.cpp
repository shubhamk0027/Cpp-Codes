#include<bits/stdc++.h>
using namespace std;
#define ll  long long
// [2 <= L < U <= 2147483647] [U-L <= 1000000] || t<150 O(150*10^6) =O(1.5*10^8) in 1 sec
const ll NMAX =1e6+20;
bool isPrime[NMAX];
vector<ll> primes;

bool seive(){
    // now we have all the numbers less than the sqrt of upto
    fill(isPrime,isPrime+ sizeof isPrime,1);
    primes.push_back(2);
    for(ll i=3; i<NMAX;i+=2) if(isPrime[i]){
        for(ll j=i*2;j<NMAX;j+=i) isPrime[j]=0;
        primes.push_back(i);
    }
    // cerr<<primes.size()<<" ";
    // cout<<primes[0]<<" "<<primes.back()<<"\n";
}

/*
Generally in order to test is the number is prime or not we try to check if it is a numtiple of any of the number less than its sqrt(Since sqrt is the highest pNo if dividing N+i) 
So for a+ 0 --> 2...sqrt1
       ....
       ....
and for..b. --> 2...sqrt2
Complexity: O(t*(b-a)*sqrt(b))
If we simply stor all 2..sqrt2 numbers and check if 
N+a...N+b is divisible or not
COmplexity(O(t*(b-a)*(U-L)log(log(U-L))
T(N)= O(150*(10^6*10)) THIS WILL ROCK!! 
*/

int main() {
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
    ll t,lo;
    ll  a,b,i;
    cin>>t;
    seive();
    while(t--){
        cin>>a>>b;
        fill(isPrime,isPrime+b-a+1,1);
        for( i=0; i<primes.size() && primes[i]<=b ;i++){
            lo = (a/primes[i])*primes[i];
            if(lo<a)lo+=primes[i];
            if(lo==primes[i]) isPrime[lo-a]=1, lo+=primes[i];
            for(;lo<=b;lo+=primes[i]) isPrime[lo-a]=0;
        }
        for(lo=0;lo<=b-a;lo++) if(isPrime[lo]) cout<<lo+a<<"\n"; 
    }
    return 0;
}