#include<iostream>
using namespace std;
long long m =1e9+7;

void EE(int a, int b, int& x, int& y){
    if(a%b == 0){x=0,y=1;return;}
    EE(b,a%b,x,y);int t = x;x = y;y = t - y*(a/b);
}
int mmi(int a){int x,y;EE(a,m,x,y);x = (x+m)%m;return x;}


int main(){
    int n;
    cin>>n;
    cout<<(1LL*n*mmi(n))%m;
    return 0;
}