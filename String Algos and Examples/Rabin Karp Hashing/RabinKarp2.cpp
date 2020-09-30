#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
const ll M1 =1e9+7, B1 =127;
const ll M2 =1e9+9, B2 =131;
string to,s;

void rabinKarpDouble(){
    ll ht1=0, tmp1=0, ht2=0, tmp2=0,s1=s.size(),b1=1,b2;
    for(int i=0;i<s1;i++) {
        ht1= ((ht1*B1)%M1 +(s[i]))%M1;
        tmp1=((tmp1*B1)%M1+(to[i]))%M1;
        ht2= ((ht2*B2)%M2 +(s[i]))%M2;
        tmp2=((tmp2*B2)%M2+(to[i]))%M2;
        if(i) b1=(b1*B1)%M1 ,b2=(b2*B2)%M2;
    }
    for(int i=s1;i<to.size();i++){
        if(tmp1==ht1 && tmp2==ht2) cout<<i-s1<<"\n";
        tmp1 =  (M1+tmp1-(b1*(to[i-s1]))%M1)%M1;
        tmp1 =  (tmp1*B1 + to[i])%M1;
        tmp2 =  (M2+tmp2-(b2*(to[i-s1]))%M2)%M2;
        tmp2 =  (tmp2*B2 + to[i])%M2;
    }
    if(tmp1==ht1 && tmp2==ht2)  cout<<to.size()-s1<<"\n";
}


int main() {
    fastio;
    int n;
    while(cin>>n){
        cin>>s>>to;
        rabinKarpDouble();
        cout<<"\n";
    }
    return 0;
}