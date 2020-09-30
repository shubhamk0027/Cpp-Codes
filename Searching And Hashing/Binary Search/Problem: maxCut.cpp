// Our barbershop opens at 9:00 am and closes at 5:00 pm, but (of course) the barber keeps working until all the customers who entered the shop before 5:00 have been served. Each customer enters the shop and if the barber is free, immediately starts getting his hair cut. Otherwise, the customer waits until everyone who entered before him has finished getting their hair cut.
// We have the sequence of times when customers entered the shop and we know when the last customer left the shop. We also know that each haircut took at least 5 minutes. We want to get a bound on how long the longest haircut took.
// Create a class HairCuts that contains a method maxCut that is given String[] enter and String lastExit and that returns the smallest possible time (in minutes) that the longest haircut took. If the inputs are inconsistent with the rule that each haircut takes at least 5 minutes, return -1.
// The enter times and the lastExit are 5 character Strings in the format hh:mm with hh being a 12 hour time.	
#include<bits/stdc++.h>

using namespace std;
int main(){
	int n,lastExit,a,b;
	cin>>n>>a>>b;
	if(a<9) a+=12;
	lastExit = a*60+b;
	vector<int> enter(n);
	for(int i=0; i<n;i++){
		cin>>a>>b;
		if(a<9)a+=12;
		enter[i]=a*60+b;
	}
	sort(enter.begin(),enter.end());
	double lo=0, hi=1440,mid,px,temp;
	while(lo<hi-1e-9){
		mid=(hi+lo)/2;
		px=0;
		for(int i=0; i<n;i++){
			px=max(px,enter[i]*1.0)+mid;
		}
		px-=lastExit;
		if(px<0) lo=mid;
		else hi=mid;
	}
	cout<<lo;
	return 0;
}