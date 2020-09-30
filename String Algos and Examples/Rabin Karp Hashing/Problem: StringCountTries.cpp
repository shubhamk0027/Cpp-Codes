#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
const ll mod =1e9+7;
const int N =1e5+1;

struct trie{
    vi ids;
    trie* next[26];
    trie(){ for(int i=0;i<26;i++) next[i]=NULL;}
};
trie* root= new trie();

void insert(string s, int id){
    trie* trav=root;
    char ch;
    for(int i=0;i<s.size();i++) {
        ch=s[i]-'a';
        if(trav->next[ch]==NULL) trav->next[ch]= new trie();
        trav=trav->next[ch];
    }
    if(!trav->ids.size() || trav->ids.back()!=id) trav->ids.pb(id);
}

int search(int &l,int &r, string &s){
    trie* trav=root;
    char ch;
    for(int i=0;i<s.size();i++){
        ch=s[i]-'a';
        if(trav->next[ch]==NULL) return 0;
        trav=trav->next[ch];
    }
    return (
        upper_bound(trav->ids.begin(),trav->ids.end(),r)-       // greater than r
        lower_bound(trav->ids.begin(),trav->ids.end(),l)        // <=l
    );
}

int main() {
    string s;
    int n,m,l,r;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s;
        for(int len=1;len<=s.size();len++)
        for(int j=0;j<=s.size()-len;j++) insert(s.substr(j,len),i);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>l>>r>>s;
        cout<<search(l,r,s)<<"\n";
    }
    return 0;
}