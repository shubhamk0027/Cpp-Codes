#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool palindromecheck(int num){
    int num2=0;
    int onum=num;
    while(num){
        num2=num2*10+num%10;
        num/=10;
    }
    return onum==num2;
}

//given smallest prod=143*707. But we have to start with 101

int main() {
    int t,n,temp;
    cin>>t;
    //make array............We created an array initially because this will have a definite comlpexity which is les than the worst.
    vector <int> A(100000);
    int index=0;
    for(int i=101;i<1000;i++)
        for(int j=101;j<1000;j++)
        {  temp=i*j;
          if(palindromecheck(temp))
          {A[index]=temp;
            index++;}
        }
  
    while(t--){
        cin>>n;
        int max=0;
        for(int i=0 ;i<index;i++)
         if(A[i]<n&&A[i]>max)
            max=A[i];
        
        cout<<max<<"\n";
    }
    return 0;
}
