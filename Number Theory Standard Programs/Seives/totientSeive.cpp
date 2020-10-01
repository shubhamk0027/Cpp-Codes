#include<iostream>
#include<cmath>
const int upto=100;
using namespace std;

// TC:  summation:(1/n) where n is a prime =O(NloglogN)
// =summation of prime harmonic series of n
int totient[upto + 1];

// the number of positive integers less than a that is relatively prime to a
void buildTotientSeive(){
    for (int i = 1; i <= upto; ++i) totient[i] = i;
    for (int i = 2; i <= upto; ++i)
    if (totient[i] == i)
    for (int j = i; j <= upto; j += i)
    totient[j] -= totient[j] / i;
}

int main(){
    int n;
    cin>>n;
    buildTotientSeive();
    cout<<totient[n];
    return 0;
}