#include<bits/stdc++.h>
using namespace std;
const int N=2e6;

int n,nn;
string s, ar[N];
// using dynamic prigramming in O(n1*n2*n3*n4..)
// using SA in O(NlogNlogN)

int own[N];
namespace suffixArray{
    int sa[N],lcp[N],val[N];
    int tmp[N],gap;
    bool comp(int i, int j){
        if(val[i]!=val[j]) return val[i]<val[j];
        return (i+gap<nn &&  j+gap<nn)?val[i+gap]<val[j+gap]:i>j; // else in descending order
    }
    void build(){   
        for(int i=0;i<nn;i++) val[i]=s[i],sa[i]=i;
        for(gap=1;gap<nn;gap<<=1){   // though gap=n is valid but no comparision pair will be there!
            sort(sa,sa+nn,comp);
            for(int i=1;i<nn;i++) tmp[i]=tmp[i-1]+comp(sa[i-1],sa[i]);
            for(int i=0;i<nn;i++) val[sa[i]]=tmp[i]; 
            if(tmp[n-1]==n-1) break;
        }
    }
    int LCP(){
        for(int i=0;i<nn;i++)val[sa[i]]=i;
        map<int,int> present;
        // using the window sliding technique!
        int mxlen=0,i=n,j=n-1,len=0;
        while(i<nn){
            while(present.size()<n && j+1<nn) {
                present[own[sa[++j]]]++;
                if(len) len--;
                if(val[j]==nn-1) {len=0;continue;}
                int k=sa[val[j]+1];
                while(k+len<nn && j+len<nn && s[j+len]==s[k+len]) len++;
            }
            mxlen=max(mxlen,len);
            present[own[sa[i]]]--;
            if(present[own[sa[i]]]==0) present.erase(own[sa[i]]);
        }
        return mxlen;
    }
}
using namespace suffixArray;

int get(){
    for(int i=0;i<n;i++){
        // concatenation by unique sentinals 
        // and must be lexiographically less than all the characters in ar[i]
        // like #,$,%, 
        // lexiographically smaller to make sure all the non valid substrings are in the front of the substrings!
        // unique so that lcp of two substring never overlap
        for(int j=0;j<ar[i].size();j++) own[j+s.size()]=i;
        s+=ar[i];
        s.push_back(i+2);
    }    
    nn=s.size();
    build();
    return LCP();
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    cout<<get();
    return 0;
}