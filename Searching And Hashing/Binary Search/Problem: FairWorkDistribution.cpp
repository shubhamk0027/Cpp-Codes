#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> work,int max, int people){
    int covered=0,last_work=0;
    for(int i=0; i<work.size();i++){
        if(last_work+work[i]<=max) 
            last_work+=work[i];
        else
            last_work=0,covered++;
    }
    if(covered<=people-1) return true;
    return false;
}

int fairDistribution(vector<int> work, int people){
    int lo = *max_element(work.begin(),work.end());
    int hi = accumulate(work.begin(),work.end(),0);
    int mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(ispossible(work,mid,people))
            hi=mid;                 //discarding required numbers
        else
            lo=mid+1;               
    }
    return lo;
}

int main(){
    int n,p;
    cin>>n>>p;
    vector<int> vec(n);
    for(int i=0; i<n;i++) cin>>vec[i];
    cout<<fairDistribution(vec,n);
    return 0;
}

