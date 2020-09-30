#include<bits/stdc++.h>
/*
Given a list of integers, find the n-th smallest number, i.e., the number that appears at index n (0-based) when they are sorted in non-descending order. The numbers will be given in intervals. For example, the intervals (1, 3) and (5, 7) represent the list of numbers { 1, 2, 3, 5, 6, 7 }. A number may be present in more than one interval, and it appears in the list once for each interval it is in. For example, the intervals (1, 4) and (3, 5) represent the list of numbers { 1, 2, 3, 3, 4, 4, 5 }.
The intervals will be given as two int[]s, lowerBound and upperBound. The i-th elements of these int[]s represent the smallest and largest numbers in the i-th interval, inclusive.
	-	lowerBound will contain between 1 and 50 elements, inclusive.	
	-	upperBound will contain the same number of elements as lowerBound.
	-	Each element of lowerBound and upperBound will be between -2,000,000,000 and 2,000,000,000, inclusive.
	-	The i-th element of lowerBound will be less than or equal to the i-th element of upperBound.
	-	n will be a non-negative integer less than the total number of elements in the list, but no greater than 2,000,000,000.
{ 1, 5 }
{ 3, 7 }
4
Returns: 6
The numbers are 1, 2, 3, 5, 6 and 7. The number at index 4 is 6.
{ 1, 3 }
{ 4, 5 }
3
Returns: 3
*/

/*variant 1 easy but not much efficient because of use of predicate function
int predicate(int mid,vector<pair<int,int>> vec){
	int count=0;
	for(int i=0; i<vec.size();i++){
		if(mid>=vec[i].first && mid<=vec[i].second) count+=(mid-vec[i].first+1);
		else if(mid>vec[i].second) count+=(vec[i].second-vec[i].first+1); 
	}
	return count;
}

	int ans=-100,mid,count;
	for(int end=200;end>0;end/=2) while(predicate(ans+end,vec)<=k)ans+=end;
	cout<<ans;
*/
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector< pair<int,int>> vec(n);
	for(int i=0; i<n;i++) cin>>vec[i].first>>vec[i].second;
	int hi=20000000;
	int lo=-20000000;
	int mid,count;
	int c=0;

	//this is needed to eliminate the case of infinite loop
	//or better use mid =(lo+hi+1)/2
	for(int i=0; i<100;i++){

		mid=(lo+hi)/2;
		count=0;
		for(int i=0; i<n;i++)
			if(mid>=vec[i].first && mid<=vec[i].second) count+=(mid-vec[i].first+1);
			else if(mid>vec[i].second) count+=(vec[i].second-vec[i].first+1); 
		if(count<=k) lo=mid; 	 
		else hi=mid-1; 			
	}
	cout<<lo;
	return 0;
}

