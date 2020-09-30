#include<bits/stdc++.h>
#define vi vector<int> 
#define v(s) vector<s>
#define l long
#define ll long
#define p(s,d) printf("s,d")
#define go(i,n) for(int i=0; i<n;i++)
using namespace std;
int main(){

   long long n,temp=1,org;
   long long ans=1;
   cin>>n;
   for(int i=2; i<1001;i++){
   	 n=i;
    while(n%2==0){
      n/=2;
     temp++;
    }
    ans*=temp;  
    for(long  i=3; i<=sqrt(n);i+=2){
       if(n%i==0){
         temp=1;
         while(n%i==0){
            n/=i;
            temp++;
         }
         ans*=temp;
       }
    }
    if(n!=1)
        cout<<i<<"-->"<<ans*2-1<<"\t";
    else
        cout<<i<<"-->"<<ans-1<<"\t";
 }
return 0;
}