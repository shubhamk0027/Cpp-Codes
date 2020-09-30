#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
#define tups tuple<int,int,int>
#define mt make_tuple
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define p(tup) cout<<g0(tup)<<"-"<<g1(tup)<<" "<<g2(tup)<<"\n";
using namespace std;

//KADANES Algorithm (modified)
int mss1(vector<int> vec ,int n){
	int curr_sum 	=vec[0];
	int max_so_far	=vec[0];
	for(int i=1; i<n;i++){
		curr_sum=max(curr_sum+vec[i],vec[i]);
		max_so_far=max(curr_sum,max_so_far);
		//cout<<i<<"-"<<max_so_far<<" ";
	}
	return max_so_far;	
}	

//    -2 3 4 -1 | 2 -3 2 1
//DIVIDE AND CONQUER ALGORITHM
tups mss2(vector<int> &vec, int l, int r){
	if(l==r)	
		return mt(vec[l],l,r) ;
	
	int m=(l+r)/2;
	tups lmax = mss2(vec, l,m), rmax= mss2(vec,m+1,r);
	//*************************************************
	//below method should return 0  in case all the elements are negative
	int crmax=0, crmax1=0, crmax2=0 , curr_max=0 ;
	int lpos =m, rpos=m+1;//in case all the elements are negative, no left and right pos will be there
	//We are trying to find if the subarray includes this middle element or not by finding the sum left to the mid within l to  m and 
	//the sum right to the mid form m+1 to r. 
	//We applied this because the subarry wherever exists it will produce the gratest sum in the range l to r 
	for(int i=m-1 ;i>=l; i--){
		curr_max+=vec[i];
		if(curr_max>crmax1){
			crmax1=curr_max;
			lpos=i;
		}
	}
	curr_max=0; 
	//
	for(int i=m+1;i<=r;i++){
		curr_max+=vec[i];
		if(curr_max>crmax2){
			crmax2=curr_max;
			rpos=i;
		}
	}	 
	crmax=crmax1+crmax2+vec[m];
	//************************************************
	//p(lmax);
	//p(mt(crmax,lpos,rpos));
	//p(rmax);
	if(g0(lmax)>g0(rmax) && g0(lmax)>crmax)   return lmax;
	else if(g0(rmax)>g0(lmax) && g0(rmax)>crmax) return rmax;
	else return mt(crmax,lpos,rpos);
}

int main(){
	int n;
	vector<int> vec(n);
	cin>>n;
	for(int i=0; i<n;i++) cin>>vec[i];
	cout<< mss1(vec,n)<<" \n";
	tuple<int, int, int > res= mss2(vec, 0, n-1);
	cout<<"\nUsing divide and conquer Algo:"<<get<0>(res);
	return 0;	
}