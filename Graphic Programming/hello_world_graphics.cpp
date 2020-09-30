#include<bits/stdc++.h>
#include<graphics.h>
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

void wait_for_char() {
    int in = 0;
    while (in == 0) {
        in = getchar();
    }
}
int main() {

    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);

    circle(getmaxx()/2, getmaxy()/2, 100);

    wait_for_char();
    closegraph();
    return 0;

}