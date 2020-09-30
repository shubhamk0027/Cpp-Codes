#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;

string s;
int n,c1,c2;

// not able to get the formula->
// https://discuss.codechef.com/t/tandem-editorial/12592
// https://www.codechef.com/viewsolution/17973679
// https://www.codechef.com/viewsolution/24082752 -> Hashing+Binary Search
/*
// USING STRING HASHING +BINARY SEARCH!!!!!!s
ll gethash(int i,int j)
{
    int len = j-i+1;
    while(j>=n);
    if(i==0)return hashr[j];
    return hashr[j]-hashr[i-1]*p[len] ;
}
int getmin(int i,int j,int k)
{
    int len=j-i ;
    int l = max(i-len+1,0)-1,r=i+1;
    while(l+1<r)
    {
        if(gethash(mid,i)==gethash(mid+len,j)
           &&gethash(mid,i)==gethash(mid+2*len,k))r=mid;
        else l=mid;
    }
    return r;
}
*/
namespace suffixArray{
    int lcp[N], val[N],sa[N],tmp[N],gap;
    bool comp(int x, int y){
        if(val[x]!=val[y]) return val[x]<val[y];
        return (x+gap<n && y+gap<n)?val[x+gap]<val[y+gap]:x>y;
    }
    void build(){
        for(int i=0;i<n;i++) sa[i]=i,val[i]=s[i];
        for(gap=1;gap<n;gap<<=1){
            sort(sa,sa+n,comp);
            for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+comp(sa[i-1],sa[i]);
            for(int i=0;i<n;i++) val[sa[i]]=tmp[i];
            if(tmp[n-1]==n-1) break;
        }
    }
    void LCP(){
        for(int i=0;i<n;i++) val[sa[i]]=i;
        int k=0;
        for(int i=0;i<n;i++){
            if(val[i]<n-1){
                int j=sa[val[i]+1];
                while(i+k<n && j+k<n &&s[i+k]==s[j+k]) k++; 
            }else k=0;
            lcp[val[i]]=k;
            if(k) k--;
        }
    }
}
using namespace suffixArray;

struct RMQ{
    int sp[N][20],lg[N],rank[N];
    void build(){
        memset(sp,0,sizeof sp);
        for(int i=0;i<n;i++) {
            sp[i][0]=lcp[i];    // sp[i][0]=n-sa[i]; sp[i][1]=lcp[i];
            lg[i+2]=lg[(i+2)>>1]+1;
            rank[i]=val[i];
        }
        for(int j=1;(1<<j)<=n;j++)       
            for(int i=0;i<n;i++){
                int k=i+(1<<j-1);
                if(k<n) sp[i][j]=min(sp[i][j-1],sp[k][j-1]);
                else sp[i][j]=sp[i][j-1];
            } 
    }

    int query(int l, int r){ 
        l=rank[l],r=rank[r];
        int to=lg[r-l];
        return min(sp[l][to],sp[r-1<<to][to]);
    }
};


RMQ rmqP;   // s[i....n-1],s[j...n-1]
RMQ rmqS;   // s[0......i],s[0.....j]

int query(int i, int j,int k,int ty){
    if(ty==0) i=rmqP.rank[i],j=rmqP.rank[j],k=rmqP.rank[k];
    else i=rmqS.rank[i],j=rmqS.rank[j],k=rmqS.rank[k];
    int l=min(i,min(j,k)), r=max(i,max(j,k));
    return ty? rmqS.query(l,r) : rmqP.query(l,r);
}

void compute(){
    // consider the indices->0,l,2l,3l.... for any l
    // any tanadem of length 3l will include, 3 of consecutive indices!
    // and we can count the number of tanadem of length l including these points!
    for(int len=1;len<=n/3;len++)
        for(int i=0;i+2*len<n;i+=len){
            int j=i+len, k=j+len;
            int pref=  min(len+1,query(i,j,k,0));
            int suff=  min(len,query(n-1-i,n-1-j,n-1-k,1));
            cerr<<pref<<" "<<suff<<"\n";
            int v= min(pref,len)+suff-1;
            if(v<len) continue;
            if(pref>len) c1+=v-len+1;
            else c1+=v-len, c2++;
        }
}   

int main(){
    // cin>>s;
    s="abaaabaaabaaabbbb";
    n=s.size();    

    build();
    LCP();
    rmqP.build();

    reverse(s.begin(),s.end());
    build();
    LCP();
    rmqS.build();

    compute();
    cout<<c1<<" "<<c2;
    return 0;
}
