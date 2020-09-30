#include<bits/stdc++.h>
using namespace std;

// gold/silver in inc order so left to right for silver!
bool comp(pair<int,int> &s1, pair<int,int> &s2){
    return s1.second*s2.first<s1.first*s2.second;
}

class PreciousStones{
    public:

    bool check(double mid,vector<pair<int,int>>&vp){
        int n=vp.size();
        int c1=0,c2=0,t1=0,t2=0;
        double s, g;
        while(c1<n && t1+vp[c1].first<mid) t1+=vp[c1++].first;
        while(c2<n && t2+vp[n-1-c2].second<mid) t2+=vp[n-1-c2++].second;
        if(c1!=n) s=c1+(mid-t1)/vp[c1].first;       else s=c1; 
        if(c2!=n) g=c2+(mid-t2)/vp[n-1-c2].second;  else g=c2; 
        return g+s<=n;
    }

    double value(vector<int>silver, vector<int> gold){
        vector<pair<int,int>> vp;

        for(int i=0;i<silver.size();i++) 
            if(gold[i]||silver[i])
                vp.push_back({silver[i],gold[i]});

        sort(vp.begin(),vp.end(),comp);

        // The ultimate conditions in a binary search!!!!
        if(vp.size()==0) return 0;
        // remember the possible errors we can have in a binary search!

        double lo=0,hi=5000,mid;
        for(int i=0;i<80;i++){
            mid=(hi+lo)*0.5;
            if(check(mid,vp)) lo=mid;
            else hi=mid;
        }
        return lo;
    }
};

int main(){
    PreciousStones p;
    double x=p.value(
 		// {46, 26, 42, 65, 97}, {98, 83, 93, 30, 86}	
         	// {71, 98, 17, 0, 59}, {40, 0, 84, 1, 54}
             	// {10, 6}, {3, 10}
                 	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
);  
    printf("%.10lf",x);
    return 0;
}