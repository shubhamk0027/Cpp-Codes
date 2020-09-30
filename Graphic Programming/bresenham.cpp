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

void bresenham(int x0, int y0, int x1, int y1) {

    int dx = abs(x1-x0), dy = abs(y1 - y0);
    int twoDy = 2*dy;
    int twoDyDx = 2*(dy - dx);

    int p = 2*dy - dx;

    int x, y, xEnd;

    if(x0 > x1) {
        x = x1;
        y = y1;
        xEnd = x0;
    }

    else {
        x = x0;
        y = y0;
        xEnd = x1;
    }
    putpixel(x, y, YELLOW);
    while(x < xEnd) {
        x++;
        if(p > 0) {
            y++;
            p += twoDyDx;
        }

        else {
            p += twoDy;
        }
        cout<<"("<<x<<","<<y<<")\n";
        putpixel(x , y , YELLOW);
    }
}

int main() {

    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);

    bresenham(50, 50, 200, 100);

    wait_for_char();
    closegraph();
    return 0;

}