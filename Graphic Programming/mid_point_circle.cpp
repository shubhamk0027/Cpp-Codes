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

void midPointCircleDraw(int x_centre, int y_centre, int r) 
{ 
    int x = r, y = 0; 
      
    // Printing the initial point on the axes  
    // after translation 
    cout << "(" << x + x_centre << ", " << y + y_centre << ") "; 
    putpixel(x+x_centre, y+y_centre, RED);
  
    // When radius is zero only a single 
    // point will be printed 
    if (r > 0) 
    { 
        cout << "(" << x + x_centre << ", " << -y + y_centre << ") "; 
        putpixel(x+x_centre, -y+y_centre, RED);

        cout << "(" << y + x_centre << ", " << x + y_centre << ") "; 
        putpixel(y+x_centre, x+y_centre, RED);
        
        cout << "(" << -y + x_centre << ", " << x + y_centre << ")\n"; 
        putpixel(-y+x_centre, x+y_centre, RED);

    } 
      
    // Initialising the value of P 
    int P = 1 - r; 
    while (x > y) 
    {  
        y++; 
          
        // Mid-point is inside or on the perimeter 
        if (P <= 0) 
            P = P + 2*y + 1; 
        // Mid-point is outside the perimeter 
        else
        { 
            x--; 
            P = P + 2*y - 2*x + 1; 
        } 
          
        // All the perimeter points have already been printed 
        if (x < y) 
            break; 
          
        // Printing the generated point and its reflection 
        // in the other octants after translation 
        cout << "(" << x + x_centre << ", " << y + y_centre << ") "; 
        putpixel(x+x_centre, y+y_centre, RED);
        
        cout << "(" << -x + x_centre << ", " << y + y_centre << ") "; 
        putpixel(-x+x_centre, y+y_centre, RED);
        
        cout << "(" << x + x_centre << ", " << -y + y_centre << ") "; 
        putpixel(x+x_centre, -y+y_centre, RED);
        
        cout << "(" << -x + x_centre << ", " << -y + y_centre << ")\n"; 
        putpixel(-x+x_centre, -y+y_centre, RED);  
        // If the generated point is on the line x = y then  
        // the perimeter points have already been printed 
        if (x != y) 
        { 
            cout << "(" << y + x_centre << ", " << x + y_centre << ") "; 
            putpixel(y+x_centre, x+y_centre, RED);  
            
            cout << "(" << -y + x_centre << ", " << x + y_centre << ") "; 
            putpixel(-y+x_centre, x+y_centre, RED);  
            
            cout << "(" << y + x_centre << ", " << -x + y_centre << ") "; 
            putpixel(y+x_centre, -x+y_centre, RED);  
            
            cout << "(" << -y + x_centre << ", " << -x + y_centre << ")\n"; 
            putpixel(-y+x_centre, -x+y_centre, RED);  

        } 
    } 
} 
  
// Driver code 
int main() 
{  
    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);
    midPointCircleDraw(getmaxx()/2, getmaxy()/2, 100); 
    wait_for_char();
    closegraph();
    return 0; 
} 