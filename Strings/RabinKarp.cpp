#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
const ll M =1e9+7, B =127;
// B should be a prime number
 
string to,s;

void rabinKarp(){
    ll ht=0, tmp=0,s1=s.size(),b=1;
    for(int i=0;i<s1;i++) {
        ht= ((ht*B)%M +(s[i]))%M;
        tmp=((tmp*B)%M+(to[i]))%M;
        if(i) b=(b*B)%M;
    }
    for(int i=s1;i<to.size();i++){
        if(tmp==ht) cout<<i-s1<<"\n";
        tmp =  (M+tmp-(b*(to[i-s1]))%M)%M;
        tmp =  (tmp*B + to[i])%M;
    }
    if(tmp==ht) cout<<to.size()-s1<<"\n";
}


int main() {
    fastio;
    int n;
    while(cin>>n){
        cin>>s>>to;
        rabinKarp();
        cout<<"\n";
    }
    return 0;
}
