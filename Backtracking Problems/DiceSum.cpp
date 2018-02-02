#include<iostream>
#include<vector>

using namespace std;

int count=0;
/*
void diceSumRollsHelper(int num, int sum, vector <int> v){
    count++;
    if(num==0){
     cout<<"{ ";
     for(int /*i=0; i<v.size(); i++)
     	cout<<v[i]<<" ";
     cout<<"}\n";
    	return;
    }
    v.push_back(0);
    for(int i=0; i<6; i++){
      if(sum-i-1<0)
        continue;	
      v[v.size()-1] = i+1;
      diceSumRollsHelper(num-1, sum-i-1, v);
    }
}
When number of dice is 4 and the sum is to be 11 then the  numbers of call made is 487 but we an minimize it to 247! 
*/
//Say when the sum is 12 and the number of dices is 12 then if i is 0 or when one dice gives 1 then the remaining sum will be 11 that must be on the 
//other dice but is not possible. or the remaining sum is not between 6*1 and 1*1 so unchoose that.
void diceSumRollsHelper(int num, int sum, vector <int> v){
    count++;
    if(num==0){
     cout<<"{ ";
     for(int i=0; i<v.size(); i++)
     	cout<<v[i]<<" ";
     cout<<"}\n";
    	return;
    }
    v.push_back(0);
    for(int i=0; i<6; i++){
      if((sum-i-1)>6*(num-1)|| (sum-1-i)<(num-1))
           continue;
      v[v.size()-1] = i+1;
      diceSumRollsHelper(num-1, sum-i-1, v);
    }
}

void diceSumRolls(int num, int sum){
	vector<int> v;
	diceSumRollsHelper(num,sum, v);
}  


int main(){
int num, sum;
cout<<"Enter number andd the sum to be on the dice";
cin>>num>>sum;
diceSumRolls(num, sum);
cout<<"\n"<<count;
return 0;
}