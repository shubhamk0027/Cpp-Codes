#include<bits/stdc++.h>
using namespace std;
/*  
    Diophantine Equations: Polynomials in two or more unkonwns such that only the integer solutions are sought or studied.
    Linear Diophantine Equation: ax+by=c, where a,b,c,x and y are integers
    Cases with the problem:
    Case 1: Finding One solution
    Case 2: Finding all solutions
    Case 3: Finding number of solutions and solution in the given interval
    Case 4: Finding solution with minimum value of x+y

    Degenrate Case
    A degenerate case that need to be taken care of is when a=b=0. It is easy to see that we either have no solutions or infinitely many solutions, depending on whether c=0 or not. In the rest of this article, we will ignore this case.

    Having or not having a Solution:
        If c is divisible by gcd(a,b) then it has a solution else not
        Using Euclids Division Lemma we can get aX+bY=gcd(a,b) 
        therefore aXc/g+bYc/g= c => Xc/g and Yc/g is a soltion
            
        Now if am+bn =c  and ap+bq = c  
        then m and n can be written as
             m = s+p anf n= t+q => sa+tb=0 => s = -tb/a 
    
        Therefore a(Xc/g-tb/a) +b(Yc/g-t) = c is generalised form of all the solutions

    // Counting All Soultions:
    //     x E (xmin, xmax), y E (ymin, ymax)
    //     Suppose x = (xmin + X) and  X E (0,xmax-xmin)
    //     xmin+X = x0+t => t = (xmin-x0)+X 
    //     and for each X from 0....xmax-xmin will satisfy the equation
    //     Say
    //         0......xmax-xmin corresponds to y1...y2 (decreasing order)
    //     Therefore there will be-
    //         0......ymax-ymin/y2 solutions
    //         ie min(abs(ymax-ymin),y2)-y1; 

    Counting all Soltuions:
        First, we can find a solution which have minimum value of x, such that x≥minx. To do this, we first find any solution of the Diophantine equation. Then, we shift this solution to get x≥minx (using what we know about the set of all solutions in previous section). This can be done in O(1). Denote this minimum value of x by lx1.

        Similarly, we can find the maximum value of x which satisfy x≤maxx. Denote this maximum value of x by rx1.

        Similarly, we can find the minimum value of y (y≥miny) and maximum values of y (y≤maxy). Denote the corresponding values of x by lx2 and rx2.

        The final solution is all solutions with x in intersection of [lx1,rx1] and [lx2,rx2]. Let denote this intersection by [lx,rx].

    Soltuion with min x+y value
        Here, x and y also need to be given some restriction, otherwise, the answer may become negative infinity.

        The idea is similar to previous section: We find any solution of the Diophantine equation, and then shift the solution to satisfy some conditions.

        Finally, use the knowledge of the set of all solutions to find the minimum:

        x′=x+k⋅bg,
        y′=y−k⋅ag.
        Note that x+y change as follows:

        x′+y′=x+y+k⋅(bg−ag)=x+y+k⋅b−ag
        If a<b, we need to select smallest possible value of k. If a>b, we need to select the largest possible value of k. If a=b, all solution will have the same sum x+y.
*/


// EXTENDED EUCLIDIAN ALGORITHM 
int EE(int a, int b, int& x, int& y){
    if(a%b == 0){
		x=0,y=1;
		return b;
	}
    int d=EE(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - y*(a/b);
	return d;
}

// GET ONE SOLUTION
bool solve(int a, int b, int c, int &x0, int &y0,int &g){
    g= EE(abs(a),abs(b),x0,y0);
    if(c%g) return false;
    x0 = x0*c/g;
    y0 = y0*c/g;
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}

void shiftSolution(int&x, int&y,int a, int b, int cnt){
    x+=cnt*b;
    y-=cnt*a;
}

int countSoutions(int a, int b, int c, int xmin, int xmax, int ymin, int ymax){
    int count=0,x0,y0,g;
    if(!solve(a,b,c,x0,y0,g)) return 0;
    if(a==0 && b==0) return INT_MAX;
    if(a==0 || b==0) return 1;
    a/=g,b/=g,c/=g;

    int signa = a>0? +1:-1;
    int signb = b>0? +1:-1;

    shiftSolution(x0,y0,a,b,(xmin-x0)/b);
    if(x0<xmin) shiftSolution(x0,y0,a,b,signb);
    if(x0>xmax) return 0;
    int lx1= x0;

    shiftSolution(x0,y0,a,b,(xmax-x0)/b);
    if(x0>xmax) shiftSolution(x0,y0,a,b,-signb);
    int rx1=x0;

    shiftSolution(x0,y0,a,b,-(ymin-y0)/a);
    if(y0<ymin) shiftSolution(x0,y0,a,b,-signa);
    if(y0>ymax) return 0;
    int lx2=x0;

    shiftSolution(x0,y0,a,b,-(ymax-y0)/a);
    if(y0>ymax) shiftSolution(x0,y0,a,b,signa);
    int rx2=x0;


    if(lx2>rx2) swap(lx2,rx2);
    int lx= max(lx1,lx2), rx=min(rx1,rx2);
    if(lx>rx) return 0;
    return (rx-lx)/abs(b)+1;
}