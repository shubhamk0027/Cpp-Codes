#include<iostream>
#include<cmath>
using namespace std;

long long m =1e9+7;

bool isprime(int num){
    if(num==2) return 1;
    if(num<=1||num%2==0) return 0;
    int m=sqrt(num);
    for(int i=3;i<=m;i+=2)
    if(num%i==0) return 0;
    return 1;
}

const int upto=100;
bool primes[upto+1];
void primeSeive(){
    int m= sqrt(upto);
    for(int i=2; i<=m;i++)
    if(primes[i]) for(int j=i*i;j<upto;j+=i) primes[j]=0;
}

int main(){
    int n;
    cin>>n;
    primeSeive();
    cout<<primes[n];
    cout<<isprime(n);
    return 0;
}