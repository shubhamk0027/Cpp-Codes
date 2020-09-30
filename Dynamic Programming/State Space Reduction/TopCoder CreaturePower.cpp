#include<bits/stdc++.h>
#define ll long long
const int N=2e6;
using namespace std;

class  CreatureTraining{
    public:
    // this was simple but took time to get the approach
    // need to go fast!

    ll maximumPower(vector <int> count, vector <int> power, int D){
        ll d[200][55],res[200], n=count.size();
        memset(d,0,sizeof d);
        for(int i=0;i<n;i++) d[0][i]=count[i],res[0]+=1LL*count[i]*power[i];

        // for each of the days
        for(int i=1;i<=D;i++){          
            res[i]=0;
            // go through all the past days
            for(int j=0;j<i;j++){       
                ll mx=res[j],ati=0,atj=0;
                // for each of the transfers possible
                for(int i1=0;i1<n;i1++){
                    for(int i2=i1+1;i2<n;i2++){
                        ll days= min(d[j][i1],1LL*(i-j)/(i2-i1));
                        // calculate the max res possible
                        ll curr= res[j] + 1LL*days*(power[i2]-power[i1]);
                        if(curr>mx){
                            mx=curr;
                            ati=i1,atj=i2;
                        }
                    }
                }

                // assign the max 
                if(res[i]<mx) {
                    res[i]=mx;
                    for(int k=0;k<n;k++) d[i][k]=d[j][k];
                    ll days=(ati!=atj)?min(d[j][ati],1LL*(i-j)/(atj-ati)):0;
                    d[i][ati]-=days,d[i][atj]+=days;                        
                }
            }
        }
        return res[D];   
    }
};


/*
Bluetooth->Boat Rockerz 230 In-Ear Bluetooth Headphone With Mic (Silver/Black)

SONY MDR-EX250AP/B IN-EAR HEADPHONES WITH MIC | Sony-MDR-XB55AP (1199)
    "The Sony MDR-XB55AP packs in all the Extra Bass to make your music sound boosted and entertaining.
    For sound that is baised towards the lower-end and Sennheiser's prestigious brand name in a budget, the Sennheiser CX275s does a solid job"
    https://www.headphonezone.in/blogs/buying-guide/comparison-sennheiser-cx275s-vs-sony-mdr-xb55ap
    But since 2 year warantee-> therefore Sen
SENNHEISER CX 275S IN-EAR HEADPHONES WITH MIC (1100)

Skullcandy Smokin Bud 2 S2PGFY-010 In-Ear Headphones with Mic (Black/Red)
SKULLCANDY S2PGGY-392 IN-EAR HEADPHONE WITH MIC

cx 180

JBL T200 (1,070)
JBL T150A IN-EAR HEADPHONES WITH MIC

Bluetooth->
X       JBL T205BT (1500)
(999)   boAt Rockerz 255 Sports Bluetooth Wireless Earphone with Immersive Stereo Sound and Hands Free Mic (Active Black) 
T160A

*/

