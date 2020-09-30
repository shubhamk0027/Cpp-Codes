#include<bits/stdc++.h>
#define pb push_back

using namespace std;
const int N =2e6+1;

int z[N];
// FORMER IMPLEMENTATION WAS BEST 
void zalgo(string &p, string &t){
    string ss=  p+"|"+t+">";
    int l=0,r=0;
    for(int i=1;i<ss.size();i++){
        z[i]=0;
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(ss[i+z[i]]==ss[z[i]]) z[i]++;
        if(i+z[i]-1>r) r=i+z[i]-1;
    }
}

// MY OWN IMPPLEMENTAITON IS BETTER!
int lps[N];
void kmp(string &p, string &t){
    string ss=p+"|"+t+">";
    int len=0;
    for(int i=1;i<ss.size();i++){
        lps[i]=0;
        while(len && ss[i]!=ss[len]) len=lps[len-1];
        if(ss[i]==ss[len]) lps[i]=++len;
    }
}

int p[N];
// THE FORMER IMPLEMENTAION WAS BEST!
void manacher(string &s){
    string ss="|";
    for(auto x:ss) ss.pb(x),ss.pb('|');
	int m=0,r=0;
	for(int i=1;i<ss.size();i++){
		p[i]=(i<r)?min(r-i,p[i-(m-i)]):0;
		while(i-p[i]-1>=0 && ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
		if(i+p[i]>r) r=i+p[i],m=p[i];
	}
}

int main() {
    string t,p;
    cin>>p>>t;
    return 0;
}