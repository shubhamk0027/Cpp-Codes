#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
// We can instead store the hash of the string in the map with our own hash function
// but since this hash function is already available in unordered map so better use
// unordered_map<string,vi>
map<string,vi> mp;
int n,m;

int main() {
    fastio;
    int l,r;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s;             // generating all subStrings;
        for(int j=1;j<=s.size();j++)
        for(int k=0;k<=s.size()-j;k++) mp[s.substr(k,j)].pb(i);
    }

    for(auto v: mp) 
        v.second.erase(
            unique(v.second.begin(),v.second.end()),
            v.second.end()
        );

    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>l>>r>>s;
        int a= lower_bound(mp[s].begin(),mp[s].end(),l)-mp[s].begin();// < = (equals to allowed!)
        int b= upper_bound(mp[s].begin(),mp[s].end(),r)-mp[s].begin();// just greater Than(Not equals to!)
        cerr<<b-a<<"\n";
    }
    return 0;
}