#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 2520 is the smallest number that can be divided by each of the numbers from to without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from to n?*/
//nmax=40;
int GCD(int a, int b){
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}
//a%b-> if a>b return a%b; else return a;
int main() {
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        int res=1;
        for(int i=2;i<=num;i++){
            res*=(i/GCD(i,res));
        }
        cout<<res<<"\n";
    }
    return 0;
}