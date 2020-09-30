#include<iostream>
#include<cmath>
const int upto=100;
using namespace std;

//TC O(sqrt(n))
int countdiv(int num){
    int res=2,upto=sqrt(num);
    for(int i=2; i<=upto;i++) if(num%i==0)res+=2;
    if(upto*upto==num && num>1)res--;  
    return res;
}

// TC:  summation (1/n) =O(NlogN)
int countDiv[upto];
void divSeive(){
    // by default initialized to 0
    // for(int i=0; i<=upto;i++) countDiv[i]=1;
    for(int i=1; i<=upto;i++) for(int j=i;j<=upto;j+=i) countDiv[j]++;
}


int main(){
    int n;
    cin>>n;
    divSeive();
    cout<<countDiv[n];
    return 0;
}