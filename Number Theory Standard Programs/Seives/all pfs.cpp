#include<bits/stdc++.h>
using namespace std;

const int MAX=10000;
int maxpf[MAX+1];
void buildseive(){
    for(int i=0; i<=MAX;i++) maxpf[i]=i;
    for(int i=2; i<=MAX;i++)
    if(maxpf[i]==i)for(int j=i+i; j<=MAX;j+=i) maxpf[j]=i;
}
//or generate a 2d vector to store all primefactors

int main(){
    buildseive();
    int num;
    cin>>num;
    while(num!=1){
        cout<<maxpf[num]<<" ";
        num/=maxpf[num];
    }
    return 0;
}