#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;

double dp[26][26];
class SureThing{
    int n=26;
    // this is not a probability problem
    // HINT-> "Notice that you don't care if your first guess is right or wrong --- either outcome leads to ending up with 8/3"
    // So all the paths will lead to same solution if made a correct descision! 
    // This is not a probability problem -- it is a math and logic problem. If you make the optimal wager at every step, you never care if any of your guesses are right or wrong.

    double solve(int x, int y){
        if(dp[x][y]!=0) return dp[x][y];
        double &res=dp[x][y];
        res=1;
        if(x==0) while(y--) res*=2;
        else if(y==0) while(x--) res*=2;
        else {
            // values derived from the child-->>
            double r1=solve(x-1,y);
            double r2=solve(x,y-1);
            // the results here can be divdided into success or failure
            // since both the results are possible so amount got at all the possible stages
            // should always be same!
            // should be equal to the min amount possible at that level!
            res=max(x,y)*min(r1,r2)*2.00;
            res/=(x+y);   
        }
        return res; 
    }

    public:
    double ans(int x, int y){ return solve(x,y);}
};

int main(){
    SureThing s;
    printf("%.10lf",s.ans(26,26));
    return 0;
}