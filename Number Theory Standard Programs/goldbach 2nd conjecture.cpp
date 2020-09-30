
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

#define MAXN 1000
typedef unsigned long long ULL;
typedef long long LL;

bitset<MAXN> nums;
int primes[MAXN];
int num_prime = 0;

void getPrimes(long long max) { // get all primes under max
    for(int i=2; i<=sqrt(max+0.5); i++) {
        if(nums[i] == false) {
            primes[num_prime] = i;
            num_prime++;
            for(long long n=2*i; n<max; n+=i) {
                nums[n] = true;
            }
        }
    }
    for(int i=int(sqrt(max+0.5))+1; i<max; i++) {
        if(nums[i] == false) {
            primes[num_prime] = i;
            num_prime++;
        }
    }
}

LL MultiplyMod(LL a, LL b, LL mod) { //computes a * b % mod
    ULL r = 0;
    a %= mod, b %= mod;
    while (b) {
        if (b & 1) r = (r + a) % mod;
        b >>= 1, a = ((ULL) a << 1) % mod;
    }
    return r;
}
template<typename T>
T PowerMod(T a, T n, T mod) {  //computes a^n % mod
    T r = 1;
    while (n) {
        if (n & 1) r = MultiplyMod(r, a, mod);
        n >>= 1, a = MultiplyMod(a, a, mod);
    }
    return r;
}
template<typename T>
bool isPrime(T n) { 
//determines if n is a prime number using Miller–Rabin primality test 
// from https://github.com/niklasb/tcr/blob/master/zahlentheorie/NumberTheory.cpp
    const int pn = 9, p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < pn; ++i)
        if (n % p[i] == 0) return n == p[i];
    if (n < p[pn - 1]) return 0;
    T s = 0, t = n - 1;
    while (~t & 1)
        t >>= 1, ++s;
    for (int i = 0; i < pn; ++i) {
        T pt = PowerMod<T> (p[i], t, n);
        if (pt == 1) continue;
        bool ok = 0;
        for (int j = 0; j < s && !ok; ++j) {
            if (pt == n - 1) ok = 1;
            pt = MultiplyMod(pt, pt, n);
        }
        if (!ok) return 0;
    }
    return 1;
}

int main() {
    long long n;
    cin >> n;
    
    getPrimes(MAXN);

    for(int i=0; i<num_prime; i++) {
        for(int j=i; j<num_prime; j++) {
            if(isPrime(n-primes[j]-primes[i])) {
                printf("%lld %lld %lld", primes[i], primes[j], n-primes[i]-primes[j]);
                return 0;
            }
            
        }
    }
    
    return 0;
}