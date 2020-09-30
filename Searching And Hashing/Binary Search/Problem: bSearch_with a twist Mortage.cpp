#include<bits/stdc++.h>
/*
When purchasing a new home, the purchasers often take out a loan to pay for it. In this problem, we will be considering loans with the following terms:
At the beginning of each month, the purchasers pay a fixed amount towards settling the loan, which decreases the amount they owe.
At the end of the month, the amount the purchasers owe increases due to interest. Each month, 1/12 of the annual interest rate is added to the amount owed. Hence, if the annual interest rate is 12%, then the debt increases by 1% each month. You may assume that the amount owed after adding interest is always rounded up to the nearest dollar greater than or equal to the actual value.
Your task is, given the annual interest rate in tenths of a percent, the original amount of the loan, and the period over which the loan is to be repaid, calculate the minimum integral monthly payment so that the loan is repaid in term years or less. All monetary units are in dollars
*/
using namespace std;
int main(){
	long long loan,term;
	double interest;
	cin>>loan>>interest>>term;
	interest/=12000;
	term*=12;
	long long lo=1, hi=loan, res,mid;
	//setting low to 1 as 0 is not possible and any value of low between 0 and 1 will be equated to 1
	//Since on each term the resultant is an integer we have to check the total iteratively for each possible value
	while(hi>lo){
		mid=(hi+lo)/2;
		// res=mid*(1-1/(pow((interest+1),term*12)))/interest;
		// This is wrong as the result in each term is paid as a dollar value not as a double value whose sum may differ form this value of res;
		res=loan;
		bool ok =true;
		for(int i=0; i<term;i++){
			res-=mid;
			if(res<0) {
				ok =false; 
				break;
			}
			res=res*(1+interest)+0.5;
		}
		if(ok) lo=mid+1; 
		//because we do not want to consider the negative values at all!
		else hi=mid;
	}
	cout<<lo;
	return 0;
}

