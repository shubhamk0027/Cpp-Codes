#include <stdio.h>
#include <math.h>

unsigned long ndiv[3001] ={3};
unsigned long lastnum=2;
unsigned long lastsum=3;
unsigned short delta,len=1;

//For loops are heavy as it does adds two extra things(checking and incrememntation) in each iteration
//efficiently printing all the divisiors of a number->
//We should not use global variables in loops as they are stores at some differnt space
//Hence, the compiler cannot cache the value of a global variable in a register

unsigned long overNdiv(int N){
   if(N<=len)    
    return ndiv[N-1];
    
  int n=len+1;  
 //since n is the searching element so <=N
  while(n<=N){
     lastnum++;
     lastsum+=lastnum;
     
         int count=2;
         long sqr=sqrt(lastsum);
         for(int i=2; i<=sqr;i++)
         if(lastsum%i==0)
         {if(lastsum/i==i)count++; else count+=2; }
      
      
     delta=count-(n+1);
     if(delta<0) continue;
      n+=(delta+1);
     for(int k=0; k<=delta;k++)
     {len++; ndiv[len-1]=lastsum; }
      //equalto may or may not be possible
  }  
    return lastsum;
}


int main() {
    int t, N;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);  
        printf("%ld\n",overNdiv(N));
    }
    
    return 0;
}