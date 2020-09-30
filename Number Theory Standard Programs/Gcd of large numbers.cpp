#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	int rem;
	while(b){
		rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}

int mod(string num, int a){
    int rem=0;
    for(int i=0; i<num.size();i++)
        rem=(rem*10 + (num[i]-'0'))%a;
    return rem;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a;
        string num;
        cin>>num;
        if(a==0){
            cout<<num<<"\n";
            continue;
        } 
        b=mod(num,a);
        cout<<gcd(a,b)<<"\n";
    }
    return 0;
}