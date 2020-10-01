#include<iostream>
#include<cmath>
const int upto=100;
using namespace std;

// TC:  summation (1/n)
int sumOfDiv[upto];
void sumOfDivSeive(){
    for(int i=1; i<=upto;i++) 
    for(int j=i; j<=upto;j+=i) 
    sumOfDiv[j]+=i;
}

int main(){
    int n;
    cin>>n;
    sumOfDivSeive();
    cout<<sumOfDiv[n];
    return 0;
}