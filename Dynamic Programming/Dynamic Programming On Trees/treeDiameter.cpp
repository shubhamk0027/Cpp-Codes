#include<bits/stdc++.h>
using namespace std;

const int NMAX =1000;
vector<int> adj[NMAX];
int diameter=0;
int d[NMAX], h[NMAX];

// we need to keep the height of the tree
// here there will be no case when the root is not as in case of tree pointer, so no -1 will be returned
void dfs(int s,int p){
    int maxh1=-1,maxh2=-1,dia=0;
    // adv -> in case s i a tree then diameter=0
    // in case only one subtree then diamter= maxh+1
    for(auto v: adj[s]){
        if(v==p) continue;
        dfs(v,s);
        if(h[v]>maxh1){
            maxh2 = maxh1;
            maxh1=h[v];
        }
        dia= max(dia,d[v]);
    }
    dia = max(dia,maxh1+maxh2+2);
    h[s]=maxh1+1;
    d[s]=dia;
    diameter=max(dia,diameter);
    // d[s]=diameter; is wrong since diameter is a global variable
}


int main(){
    int n;

}