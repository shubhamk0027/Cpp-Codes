const long long mod =1e9+7;
const int upto = 1000;
int fact[upto+1];
int invfact[upto+1];

void EE(int a, int b, int& x, int& y){if(a%b == 0){x=0,y=1;return;}EE(b,a%b,x,y);int t = x;x = y;y = t - y*(a/b);}
int mmi(int a){int x,y;EE(a,mod,x,y);x = (x+mod)%mod;return x;}

void buildfacts(){
    fact[1]=fact[0]=1;
    for(int i=1; i<=upto;i++) fact[i]=(1LL*fact[i-1]*i)%mod;
    for(int i=1; i<=upto;i++) invfact[i]=(1LL*invfact[i-1]*mmi(i))%mod;
}
