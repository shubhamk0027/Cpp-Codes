#include<bits/stdc++.h>
using namespace std;

int n;
const int NMAX =1000;
vector<int> adj[NMAX];
#define pii pair<int,int>
#define mp make_pair
int dist[NMAX], diameter, parent[NMAX];
// for every tree node x a value maxLength(x): the maximum length of a path that begins at node x.
// This can be solved using the property that all the longest paths starting from any node will end at one of the end points of the diamter of the tree. So all those paths will end at one of the ends of the diameter.

int bfs(int s){
    int top;
    queue<int> q;
    q.push(s);
    parent[s]=-1;
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

void dfs(int s){
    int top;
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        top =st.top();
        st.pop();
        for(auto v: adj[top]) if(dist[v]==-1){
            dist[v]= dist[top]+1;
            st.push(v);
        }    
    }
}

void computeLongestPaths(){
    for(int i=0; i<=n;i++) dist[i]=-1;
    int oneEnd = bfs(1);
    for(int i=0; i<=n;i++) dist[i]=-1;
    int otherEnd = bfs(oneEnd);
    diameter= dist[otherEnd];
    cerr<<diameter<<"\n";
    int curr = otherEnd;
    int d =0;
    for(int i=0; i<=n;i++) dist[i]=-1;
    while(curr!=-1){
        dist[curr]= max(d,abs(diameter-d));
        cerr<<dist[curr]<<" "; 
        curr = parent[curr];
        d++;
    }
    curr= otherEnd;
    while(curr!=-1){
        dfs(curr);
        curr=parent[curr];
    }
}

void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main(){
    n=15;
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,5);
    addEdge(4,3);
    addEdge(5,6);
    addEdge(6,7);
    addEdge(7,8);
    addEdge(7,11);
    addEdge(7,9);
    addEdge(9,10);
    addEdge(6,12);
    addEdge(6,13);
    addEdge(6,14);
    addEdge(14,15);
    computeLongestPaths();
    for(int i=1; i<=n;i++) cout<<dist[i]<<" ";
    return 0;
}