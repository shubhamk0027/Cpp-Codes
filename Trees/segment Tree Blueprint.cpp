#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int szeOfTree=0;
class segmentTree{
    vll st,a;
    ll n;
    ll left(ll p){return p<<1;}
    ll right(ll p){return (p<<1)+1;}
    void build(ll p,ll l,ll r)
    {
        if(l==r)
        {
            st[p]=a[l];
            return ;
        }
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        ll p1=st[left(p)];
        ll p2=st[right(p)];
        st[p]=(p1<=p2?p1:p2);
    }
    ll rmq(ll p,ll be,ll en,ll l,ll r)
    {
        if(be>r || en<l)return INT_MAX;
        if(l>=be && r<=en)return st[p];
        ll p1=rmq(left(p),be,en,l,(l+r)/2);
        ll p2=rmq(right(p),be,en,(l+r)/2+1,r);
        return min(p1,p2);
    }
    void update(ll p,ll l,ll r,ll index,ll value)
    {
        ll mid=(l+r)/2;
        if(l==r)
        {
            a[l]=value;
            st[p]=value;
            return;
        }
        if(index>=l && index<=mid)
            update(left(p),l,(l+r)/2,index,value);
        else
            update(right(p),(l+r)/2+1,r,index,value);
        st[p]=min(st[left(p)],st[right(p)]);
    }
public:
    segmentTree(const vll &A)
    {
        a=A;
        n=A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }
    ll rmq(ll i,ll j)
    {
        return rmq(1,i,j,0,n-1);
    }
    void update(ll index,ll value)
    {
        update(1,0,n-1,index,value);
    }
    void printVector()
    {
        for(ll i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(ll i=0;i<st.size();i++)
            cout<<st[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    vector<ll> v{3,4,5,1,2,7,6,8,5};
    segmentTree s(v);
    int m;
    cin>>m;
    while(m--)
    {
        int i,j;
        cin>>i>>j;
        cout<<s.rmq(i,j)<<endl;
    }
}
