/*
here are n benches in the Berland Central park. It is known that 
ai people are currently sitting on the 
i-th bench. Another 
m people are coming to the park and each of them is going to have a seat on some bench out of 
n available. Let k be the maximum number of people sitting on one bench after additional 
m people came to the park. Calculate the minimum possible 
k and the maximum possible k.Nobody leaves the taken seat during the whole process.
Print the minimum possible 
k and the maximum possible 
k, where 
k is the maximum number of people sitting on one bench after additional 
m people came to the park.
*/
//One line solution: cout<<max(vector,(k+sum(vector))/n)<<" "<<max(vector)+k;
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> vec(n);
	for(int i=0; i<n;i++)cin>>vec[i];
	sort(vec.begin(),vec.end());
	int mx,mn=0,tempk=k;
	mx=vec.back();
	int i=1;
	while(k>=(vec[i]-vec[i-1])*i && i<n  && k>0){
		k-=(vec[i]-vec[i-1])*i;
		mn=i;
		i++;
	}
	mn=vec[mn]+ceil(1.0f*k/i); 
	mn= max(mn,mx);
	cout<<mn<<" "<<mx+tempk;
	return 0;
}