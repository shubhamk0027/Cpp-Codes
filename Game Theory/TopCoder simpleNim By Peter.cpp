#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
class LongLongNim{
    public:
    int ans2(int maxN, vector<int> moves){
        int mask = (1 << 22) - 1;
        int res = -1;
        map<int, int> last ;
        vector<int> r;
        for (int i = 0; i <= maxN; ++i){
        mask <<= 1;
        ++res;
        for (int j : moves) if ((mask & (1 << j)) == 0)
            {
            ++mask;
            --res;
            break;
            }
        cout<<bitset<22>(mask)<<" "<<i<<"\n";
        mask &= (1 << 22) - 1;
        if (last.find(mask)!=last.end())
        {
            int pLength = i - last[mask];
            int cnt = (maxN - i) / pLength;
            i += cnt * pLength;
            res += cnt * (res - r[last[mask]]);
        }
        last[mask] = i;
        r.push_back(res);
        }
        return res;
    }
};