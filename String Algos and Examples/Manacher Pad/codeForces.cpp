#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define in(x) scanf("%d",&x)
#define inn(x,y) scanf("%d%d",&x,&y)
#define innn(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;
const int N=2e6+5;
const int mod=998244353;

int t,n,len;
string str;

int p[N];

void manacher(string &s){
    string ss="&|";
    for(auto x:s) ss.pb(x),ss.pb('|');
    ss.pb('?');
    for(int i=0;i<2*n+5;i++) p[i]=0;
    int m=0,r=0,mx=0;
    for(int i=2;i<ss.size()-2;i++){
        p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
        while(ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
        if(i+p[i]>r)r=i+p[i],m=i;
        if(i+p[i]==ss.size()-2) mx=max(mx,p[i]);
    }
}

int main(){
    cin>>t;
    while(t--){
        cin>>str;
        len=0;
        n=str.size();
        for(int i=0;i<n;i++) {
            if(str[i]!=str[n-1-i]) break;
            len++;
        }

        int mx=0,st=0;
        manacher(str);
        for(int i=0;i<2*n+5;i++) {
            if(p[i]){
                int ii= (i-p[i]-1)/2;
                int jj= (i+p[i]-2)/2;
                if(ii<n-jj-1){
                    if(ii<=len){
                        int tmp= ii*2+p[i];
                        if(tmp>mx) mx=tmp,st=i;
                    }
                }else{
                    if(n-1-jj<=len){
                        int tmp=(n-1-jj)*2+p[i];
                        if(tmp>mx) mx=tmp,st=i;
                    }
                }
            }
        }

        string res="";
        int ii= (st-p[st]-1)/2;
        int jj= (st+p[st]-2)/2;
        if(ii*2+p[st]==mx){
            res= str.substr(0,ii);
            reverse(res.begin(),res.end());
            res= str.substr(0,mx-ii)+res;
        }else{
            res=str.substr(jj+1);
            reverse(res.begin(),res.end());
            res= res+str.substr(ii);
        }
        cout<<res<<"\n";
    }
    return 0;
}