#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> primes={2,3};
long lastsum=5;

//,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; //total primes 25 till 100
//Global for  loop does not works
/*
vector <int> psum={0,2};
for(int i=1; i<25;i++)
    psum.push_back(primes[i]+psum[psum.size()-1]);
Since we need to traverse the array in ordeer to check till where we have to go so they will not be much benefit of taking a psum vector
*/
//Now primes has a size of 25 and psum has size of 26
//87 is not a prime!!
//57 is not a prime!!!
//91 is also not a prime!!!!

bool isprime(int num){
    int n=sqrt(num);
    for(int i=3; i<=sqrt(n);i+=2)//note that here = sign i important
        if(num%i==0)
            return false;
    return true;  
}

long  primesum(int num){
    long sum=0;
    if(primes[primes.size()-1]>=num){
        int i;
        for(i=0;primes[i]<num ;i++)
          sum+=primes[i];
        if(num==primes[i])//checking if num is = the last character
           return sum+primes[i];
        return sum;
        }
    
    int start=primes[primes.size()-1]+2;
    while(start<=num){
        if(isprime(start))
        {primes.push_back(start);
            lastsum+=start;}
        start+=2;
    }
    return lastsum;
}   


int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<primesum(n)<<"\n";//Whenever u are writing make sure u are writing \n!!!!! Commmon error
    }
    return 0;
}
