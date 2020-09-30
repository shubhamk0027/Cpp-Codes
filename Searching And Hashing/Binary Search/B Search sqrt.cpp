#include<iostream>
// #define del 0.0000000
// #define del 0.00000 not possible
#define del 0.00001
using namespace std;


int sqrt1(int n){
	int end,ans=0;
	for(end=n/2;end>0;end/=2) 
	while((end+ans)*(end+ans)<=n) ans+=end;
	return ans; 
}
float sqrt2(int n){
    double ans=sqrt1(n);
	double end=1;
	for(end=1;end>=del;end/=10)
		while((end+ans)*(end+ans)<=n) ans+=end;
	return ans; 
}

int main(){
	int n;
	cin>>n;
	cout<<sqrt2(n);
	return 0;
}