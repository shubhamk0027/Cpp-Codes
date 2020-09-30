#include<bits/stdc++.h>
//0    45    60
//- - - + + + +   px


using namespace std;
int main(){
	int width, height, shapes;
	cin>>width>>height>>shapes;
	while(shapes--){
		int a ,b;
		cin>>a>>b;
		if(a>width && b>height) {
			cout<<"NO/n"; 
			continue;
		}
		double hi,lo,mid,px;
		hi=M_PI/2;lo=0;
		if(a<width){
			while(hi-lo>1e-9){
				mid=(hi+lo)/2;
				px= a*cos(mid)+b*sin(mid)-width;
				if(px<0) hi=mid;
				else lo=mid;
				cout<<lo<<" "<<hi<<" "<<px<<" "<<"\n";
			}
		}else{
			while(hi-lo>1e-9){
				mid=(hi+lo)/2;
				px=a*sin(mid)+b*cos(mid)-height;
				if(px<0) lo=mid;
				hi=mid; 
				cout<<lo<<" "<<hi<<" "<<px<<" "<<"\n";
			}
		}
		if(a*cos(lo)+b*sin(lo)<=width && a*sin(lo)+b*cos(lo)<=height)
		cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}