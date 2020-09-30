#include<bits/stdc++.h>
using namespace std;

pair<int,int> search(vector< vector<int> > vec, int x){
    int lr=0,lc=0;
    int hr=vec.size()-1,hc=vec[0].size()-1;
    int mr, mc;
    while(lr!=hr || lc!=hc){
        mr=(lr+hr)/2,mc=(lc+hc)/2;
        cout<<"("<<lr<<" "<<lc<<") ("<<mr<<" "<<mc<<") ("<<hr<<" "<<hc<<")\n";
        if(vec[mr][mc]>=x) hr=mr,hc=mc;
        else if(vec[mr][hc]>=x) hr=mr,lc=mc+1;
        else if(vec[hr][mc]>=x) hc=mc,lr=mr+1;
        else lr=mr+1,lc=mc+1;
    }
    if(vec[lr][lc]==x)
    return make_pair(lr,lc);
    return make_pair(-1,-1);
}

int main(){
    int n, m;
    n=4,m=5;
    vector< vector<int> >vec ={
        {1,2,  3,4,5},
        {2,3,  8,9,10},
        
        {3,4,  8,12,13},
        {5,6,  9,12,14}
    };
    int x=13;
    cin>>x;
    auto pii = search(vec,x);
    cout<<pii.first<<" "<<pii.second;
    return 0;
}