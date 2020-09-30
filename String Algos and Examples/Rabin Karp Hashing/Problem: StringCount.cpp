//https://www.hackerearth.com/problem/algorithm/substrings-count-3/
#include<bits/stdc++.h>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;

const int N =1e4+1;

string arr[N];
int ans[50*N],n,m;


unordered_map<string,int> freq;
unordered_map<string,unordered_set<string>> subStrings;
void pre(){
    for(int i=1;i<=n;i++) for(int j=1;j<=arr[i].size();j++)
    for(int k=0;k<=arr[i].size()-j;k++) subStrings[arr[i]].insert(arr[i].substr(k,j));
}
const int SZ=sqrt(N);

struct Q{ 
    int l,r,id;
    string str;
} q[50*N];

namespace MOS{
    bool comp(Q&a,Q&b){
        if(a.l/SZ!=b.l/SZ) return a.l/SZ < b.l/SZ;
        return a.r<b.r;
    }
    void add(int id){
        for(auto s:subStrings[arr[id]]) freq[s]++;
    }
    void remove(int id){
        for(auto s:subStrings[arr[id]]) {
            freq[s]--;
            if(freq[s]==0) freq.erase(s);
        }
    }
    void mos(){
        sort(q+1,q+m+1,comp);
        int mosl=1,mosr=0,res;
        for(int i=1;i<=m;i++){
            while(mosl<q[i].l) remove(mosl++);
            while(mosl>q[i].l) add(--mosl);
            while(mosr<q[i].r) add(++mosr);
            while(mosr>q[i].r) remove(mosr--);
            if(freq.count(q[i].str)) res=freq[q[i].str];
            else res=0;
            ans[q[i].id]=res;
        }
    }
}

int main() {
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>q[i].l>>q[i].r>>q[i].str,q[i].id=i;
    pre();
    MOS::mos();
    for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
    return 0;
}



