
#include<iostream>
#include<cmath>
const int upto=100;
using namespace std;

// TC:  summation:(1/n) where n is a prime =O(NloglogN)
// =summation of prime harmonic series of n
int big[upto + 1] = {1, 1};

// the number of positive integers less than a that is relatively prime to a
void bigPrimeSeive(){
    for (int i = 1; i <=upto; ++i)
    if (big[i] == 1)
        for (int j = i; j <=upto; j += i)big[j] = i;
}

int main(){
    int n;
    cin>>n;
    bigPrimeSeive();
    cout<<big[n];
    return 0;
}