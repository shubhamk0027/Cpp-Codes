#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector< int> prime={1,7,11,13,17,19,23,29};
//index               4, 5, 6, 7, 8, 9,10
//index           11,12,13,14,15,16,17,18
//index           19,20,21,22,23,24
//there are 10 prime in range from 1 to 30 
//2,3 and 5 does not repeats itself
//1 is not a prime bu(30n+1) is; 

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1)
        {cout<<"2\n";continue;}
        if(n==2)
        {cout<<"3\n";continue;}
        if(n==3)
        {cout<<"5\n";continue;}
        if(n<11)
        {cout<<prime[n-3];continue;}
        n-=3;
        int p=(n/8)*30+prime[(n)%8];
        cout<<p<<"\n";
    }
    return 0;
}
