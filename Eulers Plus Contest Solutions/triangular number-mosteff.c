#include <stdio.h>
#include <math.h>

/* Global variables are stored at a different space and are not copied to cache. So if we are using a for loop and that involves global variables then its time 
willl increace as these ar not stored in the registers.
So in questions of dp. try to decrease the number of global varibles by decreasing the number of functions and writing the code in the main. Although it is not possible
to do that always!
*/

int numfac(long num){
    int res=1;
    int count=0;
    
    //Surely this for loop is better than finding divisiors for loop ehere the sqrt is fixed.
    if(num%2==0){
          while(num%2==0)
          {num/=2;count++;}   
        res*=(count+1);}
      
    for(int i=3; i<=sqrt(num); i+=2)
      if(num%i==0){
         count=0;//imp
          while(num%i==0)
          {num/=i;count++;}   
          res*=(count+1);
        }
    
    if(num!=1)
      res*=2;
    return res;
}


int main() {
     int t, N;   
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
       
        long sum=3;
        for(int i=3;;i++){
            if(numfac(sum)>N)
              break;
            sum+=i;
            
        }
      printf("%ld\n",sum);
    }
    return 0;
}