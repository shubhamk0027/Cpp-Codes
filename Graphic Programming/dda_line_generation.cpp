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

void DDA(int X0, int Y0, int X1, int Y1) 
{ 
     
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
     
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
     
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
     
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        putpixel (X,Y,RED);   
        X += Xinc;            
        Y += Yinc;                       
                             
    } 
} 

int main() {

    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);

    DDA(0,0, 500, 400);
    
    wait_for_char();
    closegraph();
    return 0;

}