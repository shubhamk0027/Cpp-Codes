#include<iostream>
using namespace std;
long long m =1e9+7;

int mod(string s, int n){
    int res=0;
    for(int i=0; i<s.size();i++) res=(res*10+(s[i]-'0'))%n;
    return res;
}

int main(){
    int n;
    string s;
    cin>>s>>n;
    cout<<mod(s,n);
    return 0;
}