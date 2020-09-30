//Ques 
//if n is odd n= n*3+1
//else n= n/2
//find min number of steps to reach 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//returns terms at num and consequitevely builds up res(number with max terms yet)
int collatzterms(long num,vector<int> &terms){
    if(num<4999999)
        if(terms[num-1] > 0)
          return terms[num-1];
    int count=1;
    if(num%2==0)
        count+=collatzterms(num/2,terms);
    else
        count+=collatzterms(num*3+1,terms);
    if(num<4999999)
        terms[num-1]=count; //This is not the correct lace to modify!!!
    return count;
}    

//Since the inputs are large we better use dp to store the results
int main() {
    vector <int> terms (5000000);//stores count
    vector <int> res ={1,2};//stores answers
    terms[0]=1;
    terms[1]=2;
    long t,ans,n,count,maxcount=2;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=res.size()){
           cout<<res[n-1]<<"\n";
            continue;
        }
        for(long i=res.size()+1;i<=n;i++){
            count =  collatzterms(i,terms);
           if(count>=maxcount)
           {maxcount=count; ans=i;}
            res.push_back(ans);
        }
      cout<<ans<<"\n";
    } 
   
return 0;    
}   
    