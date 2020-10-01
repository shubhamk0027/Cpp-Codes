#include<iostream>
using namespace std;
const long long m =10e9+7;

int expo(int a, int b){
    int res=1;
    while(b){
        if(b&1) res=(1LL*res*a)%m;
        a=(1LL*a*a)%m;
        b/=2;
    }
    return res;
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<expo(a,b);
    return 0;
}