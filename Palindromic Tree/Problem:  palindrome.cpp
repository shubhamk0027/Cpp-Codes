/*
product of odd lengths
10 10 10
2 6
1 1 4
2 6
1 1 4
2 2
1 5 10
2 6
1 4 8
2 5
1 6 10
*/
        
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N=2e5+1000;
ll p[N],n,till[N];

ll manacher(string &s){
    string ss="&|";
    for(auto x:s) ss.pb(x),ss.pb('|');
    ss.pb('?');

    ll m=0,r=0,res=1;
    for(int i=2;i<ss.size()-2;i++){
        p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;

        while(ss[i+p[i]+1]==ss[i-p[i]-1]) {
            p[i]++;
            if(p[i]%2 && p[i]!=n && ss[i]!='|') {
                till[i+p[i]-1]=max(till[i+p[i]-1],p[i]); 
                res=max(res,p[i]*till[i-p[i]]);
            }
        }

        if(i+p[i]>r) r=i+p[i],m=i;
        till[i]=max(till[i-1],till[i]);

        if(p[i]%2 && p[i]!=n && ss[i]!='|') 
            res=max(res,p[i]*till[i-p[i]]);
        cerr<<till[i]<<" ";
    }

    return res;
}


int main(){
    string s;
    n=s.size();
    cin>>s;
    cout<<manacher(s);
    return 0;
}