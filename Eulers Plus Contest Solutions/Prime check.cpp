
#include<bits/stdc++.h>

//this method is wrong and does not gives correct output ex when num=77 rem=17 but is not prime
bool isprime(long num){
   //sure 2 is not comming
    if(num==3||num==5)
        return 1;
    long rem= num%30;
    if(rem==7||rem==11||rem==13||rem==17||rem==19||rem==23||rem==29||rem==1)
        return 1;
     
    return 0;
}

//Finally after 4 onths i got my answer. aaplied my own algo and tried iwith it but eery time the last case was takin much tie.. All that happened because i j=ave not taken con<=sqrtog num where num is getting updated every time!
//finl solution-------->
int main() {
    int t;
    scanf("%d",&t);
    
    while(t--){
    long num,p;  
    scanf("%ld",&num);
         while(num%2==0){
         num/=2;
         }
     if(num==1){ 
         printf("2\n");
         continue;}
      for ( long i=3;i<=sqrt(num);i+=2){
          if(num%i==0){
              p=i;   ////////no neeed to check if is is prime or not!!!
             while(num%i==0){
                    num/=i;
               }
         }
    }       
        if(num==1)
           printf("%ld\n",p);      
       else
           printf("%ld\n",num);
    }
      
    return 0;
}
