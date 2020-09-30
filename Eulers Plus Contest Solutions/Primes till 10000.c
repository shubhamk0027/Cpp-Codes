#include<stdio.h>
#include<time.h>
#include<math.h>

//This c version of the program take only 546 ms to execute
//whereas the c++ version takes 1422 ms(thrice of it!!!)
//Also rememeber that there is no bool datatype in c and the header file has .h  extension
//instead use int ans return 0 or 1 or incluse stdbool.h header file.
//Note that the header file for clock_t datatype and clock() function is not time but time.h as this header file is not in cpp but in c
//Or better use ctime for updated time header file
/*
Note that there are -
4 primes form 1 to 10
25 primes form 1 to 100
168 primes form 1 to 1000
1229 primes from 1 to 10000
9592 primes form 1 to 100,000
 Note that the wheel factorization method is wrong
 from 1 to 100 exceptions for this rule are->
 prime= 30n+(1,3,7,11,13,19,23,29)
 rems are only 8 
 so according to this form 1-30 there are 10 primes
 form 31 to 60 there are 8 but is 7 (49 is not)
 form 60 to 90 there are 8 but is 7 (77 is not)
 exceptions-> 49(30n +19) 77(30n+ 17) and 91(30n+1)
 */
int count=1;//2 included

int isprime(int num){
  int n=sqrt(num);
  for(int i=3; i<=n; i+=2)
    if(num%i==0)
        return 0;
  count++;
  return 1;
 } 

//Note that his methods only check of the number is prime or not it will not print the prime factors
//to make it print the prime factors reduce the number each time you find any factor and make it run through sqrt(num)
//make sure that u update sqrt(num) every time u update the num(divided by any factor found)... so n will not be used
// if  becomes 1 then thsi means the last value of the o found is the max prime factor
// else the n be the largest prime factor

int main(){
    clock_t beg, end;
    beg=clock();

    printf("\nPRIMES: Till 100\n2   ");
    
    for(int i=3;i<100;i+=2){
        if(isprime(i))
          printf("%d   ",i);
        //  i+=2;
        //if(isprime(i))
         // printf("%d   ",i);
    }

    printf("TOTAL PRIMES: ");
    printf("%d",count);
    printf("\nPRIMES: Till 1000\n");
    for(int i=101;i<1000;i+=2){
        if(isprime(i))
          printf("%d   ",i);
        //if(isprime(i+2))
         // printf("%d   ",i+2);
    }    
    printf("TOTAL PRIMES: ");
    printf("%d",count);
    printf("\nPRIMES: Till 10000\n");
        for(int i=1001;i<10000;i+=2){
        if(isprime(i))
          printf("%d   ",i);
       // if(isprime(i+2))
         // printf("%d   ",i+2);
    }    
    printf("TOTAL PRIMES: ");
    printf("%d",count);
    printf("\nPRIMES: Till 1000\n");
    for(int i=10001;i<100000;i+=2){
        if(isprime(i))
          printf("%d   ",i);
       //if(isprime(i+2))
         // printf("%d   ",i+2);
    }
    printf("TOTAL PRIMES: ");
    printf("%d",count);
    end=clock();
    float time=end-beg;
    //we have taken float to print the time because cout default prints the number in integer format.
    printf("\nTime taken for execution(in millisecs): %lf",time);
   return 0;

}