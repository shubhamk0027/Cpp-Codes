#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
const int mx= (1<<22)-1;

class LongLongNim{
    public:
    
    
    int fastGetCycle(vector<int> &ar){
        int setMask=0;
        for(auto xx: ar) setMask|=(1<<xx); // 23 bits!
        int mask=mx-1; // 0TH STATE 111111..110
        map<int,int> dp;
        for(int i=1;;i++){
            mask<<=1;
            if((mask&setMask)!=setMask) mask|=1;
            mask&=mx;
            if(dp[mask]) return i-1;
            dp[mask]=1;
        }
        return 1000000;
    }

    int getCycleLen(vector<int> &ar){
        int mask=mx-1;
        // FIRST 22 STATES
        // oth state of mask is not correct it is just an initial
        // value from where the first state will be build and on
        // which further states will be built
        for(int i=1;i<=22;i++){
            mask<<=1;
            for(auto xx:ar) if(((mask>>xx)&1)==0) {
                mask|=1; 
                break;
            }
            mask&=mx;
        }
        map<int,int> dp;
        dp[mask]=1;
        // cerr<<bitset<22>(mask)<<" "<<1<<"\n";
        for(int i=2;i;i++){
            // NEXT 22 STATES
            mask<<=1;
            for(auto xx:ar) if(((mask>>xx)&1)==0) {
                mask|=1;
                break;
            }
            mask&=mx;
            // cerr<<bitset<22>(mask)<<" "<<i<<"\n";
            if(dp.find(mask)==dp.end()) dp[mask]=1;
            else return i-1;
        }
        return 100000;
    }

    int numberOfWins(int maxN, vector<int> ar){
        int cycleLen= fastGetCycle(ar);
        // cout<<"LEN: "<<cycleLen<<"\n";
        vector<bool> isWin(cycleLen+1,0);
        vector<int>  dp(cycleLen+1,0);
        for(int i=1;i<=cycleLen;i++){
            for(auto xx: ar) if(xx<=i and !isWin[i-xx]) {
                isWin[i]=1;
                break;
            }
            dp[i]=dp[i-1]+!isWin[i];
        }
        return (maxN/cycleLen)*dp[cycleLen] + dp[maxN%cycleLen];
    }

};

int main(){
    LongLongNim nn;
    cout<<nn.numberOfWins(20,{1,2,3})<<"\n";
    cout<<nn.numberOfWins(1000000000,{1,2})<<"\n";
    cout<<nn.numberOfWins(6543,{2,4,7})<<"\n";
    cout<<nn.numberOfWins(
	1000000000, {15, 17, 19, 21, 22}
    );
    return 0;
}