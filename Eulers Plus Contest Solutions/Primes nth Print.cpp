
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//primes upto 100 are-
vector<int> primes ={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

//form 1 to 100 there are only 25 primes
//form 1 to 1000-> 168
//from 1 to 10000-> 1229
//from 1 to 100000->9592


bool isprime(int num){
    int n=sqrt(num);
    for(int i=3;i<=n;i+=2)
      if(num%i==0)
         return false;
    return true;
}
//91 is not a prime divisible by 7!!!
//49 is not a prime
//77 is not a prime


int printprime(int num){
    if(num <= primes.size())
        return primes[num-1];
  int count=primes.size();
  int n=primes[primes.size()-1]+2;  
  while(count!=num){
     if(isprime(n))
     { primes.push_back(n);
       count++; }
     n+=2;
    }
   return n-=2;
    
    //Error since n hase been incrementee//
}

int main() {
    int t,n;
    cin>>t;    
    while(t--){
        cin>>n;
        cout<<printprime(n)<<"\n";}
    //cout<<printprime(168);->997
    //cout<<printprime(1229);->9973
    //cout<<printprime(9592);->99991
    
    return 0;
}
