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
    
    int n;
    cin>>n;

    vi arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int max = 0;
    vi indices;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] == max) {
            indices.push_back(i);
        }
    }

    if(indices.size() == 1) {
        arr.erase(arr.begin()+indices[0]);
    }
    else {
        arr.erase(arr.begin()+indices[2]);
    }    

    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;

}