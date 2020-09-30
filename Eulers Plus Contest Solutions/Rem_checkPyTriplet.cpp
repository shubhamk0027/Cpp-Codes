#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*Here we have to choose a,b and c. We can try here brute force method where we can try all possible combinations by->
for i...<n
  for j=i+1...n
   for k=j+1....n
   and test a+b+c=N and a....
Or make a formula
a2 +b2= c2 =(N-a-b)2
=>a2 + b2= n2+a2+b2-2Na-2Nb +2ab
=> n2+2ab=2N(a+b)
=> a(2b-2N)=2Nb-n2;
Hmm lower one seems better
*/
//We also need to check if the a found has its decimal part 0;

int main() {
     int t;
     double A,b,c,num;
     long res,p,a;
     cin>>t;
     while(t--){
         res=-1; 
         cin>>num;
         //min a=1=> min b=2 and amax =n-2 bmax=n-1
         for( b=2; b<num;b++){
             A=(num*num-2*num*b)/(num-b);//the res value is dependent on the types of the var included not on the A!!! 
             A/=2;
             a=A*1000000;
             if(a%1000000!=0)
                 continue;
             a/=1000000;
             c=num-a-b;
             //Since if a will be pos so this cond willl also check for pos c
             if(a<b&&b<c && a>0){
              p=a*b*c;
                 //cout<<a<<" "<<b<<" "<<c<<" ";
              if(p>res) res=p;}
             }
     cout<<res<<"\n";
     }  
    return 0;
}
