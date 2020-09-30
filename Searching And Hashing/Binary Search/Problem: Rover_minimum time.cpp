// You are responsible for planning the operation of a remote control rover that is exploring a distant planet. Your team of scientists has identified a target of interest, and they want the rover to reach it as soon as possible. The rover can change directions in a negligible amount of time, but its maximum speed is dependent on the terrain it is traversing. Consider a rectangle with the rover's initial position and the target at opposite corners (the target is close enough that the curvature of the planet's surface can be neglected), as displayed in the example below. The rectangle is divided into parallel strips of terrain with different widths, and each strip has its own limit on the maximum speed of the rover. Your goal is to find the route that will minimize the travel time to the target.

//sqrt(100*100+x1*x1)/100 + sqrt(300*300+x2*x2)/50 +..... = tmin
//clearly the time will be proportioanl to speed in order to travel the maximum distance 

#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	long long offset,totalspeed=0;
	cin>>n>>offset;
	vector<long long> width(n), speed(n);
	for(int i=0; i<n;i++) cin>>width[i];
	for(int i=0; i<n;i++) cin>>speed[i],totalspeed+=speed[i];
	double hi,lo,mid,temp,px;
	lo=0,hi=1000;
	while(lo+1e-9<hi){
		mid=(lo+hi)/2;
		bool ok=1;
		px=0;
		for(int i=0; i<n;i++){
			temp=speed[i]*speed[i]*speed[i]*speed[i];
			temp=mid*mid*temp;
			temp= temp/(totalspeed*totalspeed) - width[i]*width[i];
			if(temp<0){
				ok=0; break;
			}
			px+=sqrt(temp);
		}
		if(px<offset||!ok) lo=mid; 
		else hi=mid;
		cout<<px<<" "<<lo<<" "<<hi<<"\n";
	}
	cout<<lo;
	return 0;
}