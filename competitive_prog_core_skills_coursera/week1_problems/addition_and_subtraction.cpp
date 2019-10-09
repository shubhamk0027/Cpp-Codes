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
typedef unsigned long long ull;
typedef vector<ull> vull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ull x, y, z;
    bool found = false;
    cin>>x>>y>>z;
    
    if(z == 0) {
        cout<<0;
        return 0;
    }
    
    vull arr(2000);
    arr[0] = 0;
    for(ull i = 1; i < 2000; i++) {

        if(i%2 != 0) {
            arr[i] = arr[i-1] + x;
        }

        else {
            arr[i] = arr[i-1] - y;
        }

    }

    //  for(ull i = 0; i < 2000; i++) {
    //      cout<<arr[i]<<" ";
    //  }

    for(ull i = 0; i < 2000; i++) {
        if(arr[i] == z) {
            //cout<<"Position of z: ";
            cout<<i;
            found = true;
            break;
        }
    }
    if(!found) {
        cout<< -1;
    }
    
    return 0;

}