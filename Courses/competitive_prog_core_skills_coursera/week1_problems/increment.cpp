#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef vector<string> vs;
typedef unordered_map<int, int> uii;
typedef unordered_map<char, int> uci;
typedef unordered_map<string, int> usi;
typedef vector< pair<int, int> > vpii;
typedef vector< pair<string, string> > vpss;
typedef set< string > ss;
typedef set< int > si;
typedef set< char > sc;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string x;
    cin>>x;

    bool foundNonNine = false;

    for(auto i = x.begin(); i != x.end(); i++) {
        if(*i != '9') {
            foundNonNine = true;
            break;
        }
    }

    if(foundNonNine == true) {
        cout << x.length();
    }

    else {
        cout<< x.length() + 1;
    }

    return 0;

}