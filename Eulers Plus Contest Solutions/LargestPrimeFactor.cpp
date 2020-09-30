#include<bits/stdc++.h>
#define vi vector<int> 
#define v(s) vector<s>
#define l long
#define ll long
#define p(s,d) printf("s,d")
#define go(i,n) for(int i=0; i<n;i++)
using namespace std;
int main(){
   long n,ans=1,temp=1;
   scanf("%ld",&n);
   while(n%2==0){
    n/=2;
    ans=2;
   }
   //It is not needed to check if n was not a multiple of 2 as if at end n==1 then this means that a factor has been found 
   for(long i=3; i<=sqrt(n);i+=2){
    if(n%i==0){
      while(n%i==0){
        n/=i;
        }
        ans=i;
        } 
   } 
   //org ==n means n is now a prime number
   //n==1 means that it can be a multiple of any number
   if(n!=1) 
      cout<<n;
   else
     cout<<ans;

return 0;
}