#include<bits/stdc++.h>
using namespace std;

int n;
const int NMAX =1000;
vector<int> adj[NMAX];
#define pii pair<int,int>
#define mp make_pair
int dist[NMAX]={-1}, diameter, parent[NMAX];

// We can start searching for the farthest node from any node!
// to go only in onde direction->
// store visited/ unvisited nodes 
// to go iff the dist[]=-1/0
// to go by checking the parent


int bfs(int s){
    int top;
    queue<int> q;
    q.push(s);
    dist[s]=0;
    int farthestNode;
    while(!q.empty()){
        top=q.front();
        q.pop();
        for(auto v: adj[top]) 
        if( dist[v]==-1){
            dist[v] =dist[top]+1;
            q.push(v);
            parent[v]=top;
        } 
        farthestNode=top;
    }
    return farthestNode;
}


int computeDiameter(){
    int oneEnd = bfs(1);
    for(int i=0; i<=n;i++) dist[i]=-1;
    int otherEnd = bfs(oneEnd);
    diameter= dist[otherEnd];
    return diameter;
}

int main(){
    int u,v,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}