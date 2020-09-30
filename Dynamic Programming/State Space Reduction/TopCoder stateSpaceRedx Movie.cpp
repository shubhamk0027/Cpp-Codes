#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int N=2e6;

// Brute Force O(2*N*N) N<=20
class 	TheMoviesLevelThreeDivTwo{
    vi ta, tb;
    int isa[20],isb[20];
    int n;
    public:
    bool check(int x){
        queue<int> a,b;
        int t1=0,t2=0;
        for(int i=0;i<n;i++) {
            isa[i]=isb[i]=0;
            if(x&(1<<i)) a.push(i); 
            else b.push(i);
        }
        while(!a.empty() && !b.empty()){
            int x1=t1+ta[a.front()],x2=t2+tb[b.front()];
            int mn=min(x1,x2);
            if(mn==x1){
                int z=a.front();
                a.pop();
                isa[z]=1;
                t1+=ta[z];
                if(!isb[z]) b.push(z);
            }
            if(mn==x2){
                int z=b.front();
                b.pop();
                t2+=tb[z];
                isb[z]=1;
                if(!isa[z]) a.push(z);
            }
        }
        if(a.size()) while(!a.empty()) isa[a.front()]=1,a.pop();
        if(b.size()) while(!b.empty()) isb[b.front()]=1,b.pop();
        for(int i=0;i<n;i++) if(!isa[i]||!isb[i]) return 0;
        return 1;
    }

    int find(vi _ta,vi _tb){
        ta=_ta,tb=_tb;
        n=ta.size();
        int cnt=0;
        for(int i=0;i<(1<<n);i++) if(check(i)) cnt++;
        return cnt;
    }
};

// State Space Reduction->
// Since N<=47 si brute force is not valid
// also simply checking each case is also not possible 
// so trying inclusion exclusion principle
// Removing the invalid from the total
class TheMoviesLevelThreeDivOne {

};

int main(){
    TheMoviesLevelThreeDivTwo m;
    cout<<m.find(
{1, 4},
{4,2}
    );    
    return 0;
}