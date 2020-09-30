#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
class LongLongNim{
    public:
    int dp[N];
    int numberOfWins(int maxN, vector<int>ar){
        dp[0]=0;
        int cnt=0;
        for(int i=1;i<N;i++){
            dp[i]=0;
            for(auto xx: ar) if(xx<=i){
                // from a winning position at least one lossing position should be there
                if(dp[i-xx]) {
                    dp[i]=1;
                    break;
                }
            }
            if(dp[i]) cnt++;
        }
        int res=(maxN/N)*cnt,rem=maxN%N;
        for(int i=0;i<rem;i++) if(dp[i]) res++;
        return res;
    }
};

int main(){
    LongLongNim nn;
    cout<<nn.numberOfWins(20,{1,2,3})<<"\n";
}