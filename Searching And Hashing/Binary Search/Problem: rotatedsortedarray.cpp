#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n;i++) cin>>vec[i];
	//6 7 8 9 10 1 2 3 4 5 
	int ans=0;
	for(int end=n-1;end>0;end/=2)
	while(vec[ans+end]>vec[0]) ans+=end;
	cout<<vec[ans+1];
	return 0;
}