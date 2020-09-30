#include<iostream>
#include<vector>
using namespace std;
// 1 1 6 12 12 12 18 20 20
// 1 2 1  1  2  3  1  1  2
int main(){
    int t,n,k;
    cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0; i<1000001;i++) count[i]=0;
		for(int i=0; i<100001;i++) sindexes[i]=0;
		for(int i=0; i<100001;i++) eindexes[i]=0;
		count[0]=1;
		sindexes[1]=0;
		cin>>vec[0];
		for(int i=1; i<n;i++){
			cin>>vec[i];
			if(vec[i-1]==vec[i]) count[i]=count[i-1];
			else {
				eindexes[count[i-1]]=i-1;
				count[i]=count[i-1]+1;
				sindexes[count[i]]=i;
			}
		}
		eindexes[count[n-1]]=n-1;
		// for(int i=0; i<10;i++) cout<<i<<"->"<<sindexes[i]<<" "<<eindexes[i]<<" "<<count[i]<<"\n";
		for(int i=0; i<k;i++){
			cin>>a>>b>>c;
			int ans=((eindexes[count[a-1]]-(a-1)+1)>=c)?1:0;
			for(int j=count[a-1]+1;j<count[b-1];j++) ans+=(((eindexes[j]-sindexes[j]+1)>=c)?1:0);
			if(count[a-1]!=count[b-1]) ans+=((((b-1)-sindexes[count[b-1]]+1)>=c)?1:0);
			cout<<ans<<"\n";
		}
        }    return 0;
}