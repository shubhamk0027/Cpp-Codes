#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    long long temp,hi=1e9 ,lo=-1e9,mid;
    cin>>n>>k;
    vector<long long> a(n),b(n);
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<n;i++){
        cin>>b[i];
        temp=a[i]*b[i];
        hi=max(temp,hi);
        lo=min(temp,lo);
    }
    long long count;
    while(lo<hi){
        mid=(lo+hi)/2;
        count=0;
        for(int i=0; i<n;i++){
            temp = mid/b[i];
            count+=max(a[i]-temp,0LL);
        }
        if(count<=k) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
    return 0;
}