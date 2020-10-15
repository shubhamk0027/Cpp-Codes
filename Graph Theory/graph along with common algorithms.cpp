#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>
#include <tuple>
using namespace std;
class compare
{
public:
    bool operator()(tuple<int,int,int> &t1,tuple<int,int,int> &t2)
    {
        if(get<2>(t1) < get<2>(t2))
            return true;
        return false;
    }
};
class UnionSet
{
    vector<int> parent;
    vector<int> sze;
    int ParentOfRoot(int curIdx)
    {
        while(curIdx!=parent[curIdx])
            curIdx=parent[curIdx];
        return curIdx;
    }
public:
    UnionSet(int numVer)
    {
        parent.resize(numVer+1);
        sze.resize(numVer+1);
        for(int i=0;i<=numVer;i++)
            parent[i]=i;
        fill(sze.begin(),sze.end(),1);
    }
    void make_set(int root1,int root2)
    {
        int parent1=ParentOfRoot(root1);
        int parent2=ParentOfRoot(root2);
        if(sze[parent1]>sze[parent2])
        {
            sze[parent1]+=sze[parent2];
            parent[parent2]=parent1;
        }
        else
        {
            sze[parent2]+=sze[parent1];
            parent[parent1]=parent2;
        }
    }
    bool isSameSet(int root1,int root2)
    {
        return ParentOfRoot(root1)==ParentOfRoot(root2);
    }
};
class graph{
    map<int,list<int> > myMap;
    map<int,list<pair<int,int>> > myMapWeight;
    void dfs(int source ,set<int> &visited)
    {
        visited.insert(source);
       // cout<<source<<" ";
        for(auto it:myMap[source])
        {
            if(visited.find(it)==visited.end())
            {
                visited.insert(it);
                dfs(it,visited);
            }
        }
    }
    bool dfsHelper(int source,map<int,bool> &visited,map<int,bool> &inStack)
    {
        visited[source]=true;
        inStack[source]=true;
        for(auto it:myMap[source])
        {
            if((!visited[it]&&dfsHelper(it,visited,inStack)) || inStack[it]==true)
                return true;
        }
        inStack[source]=false;
        return false;
    }
public:
    void addEdge(int a,int b,bool bidirectional=true)
    {
        myMap[a].push_back(b);
        if(bidirectional==true)
            myMap[b].push_back(a);
    }
    void addEdgeWeighted(int a,int b,int weight,bool bidir=true)
    {
        myMapWeight[a].push_back(make_pair(b,weight));
        if(bidir)
            myMapWeight[b].push_back(make_pair(a,weight));
    }
    void printGraph()
    {

        for(auto it:myMap)
        {
            cout<<it.first<<" : ";
            for(auto ij:myMap[it.first])
            {
                cout<<ij<<" ";
            }
            cout<<endl;
        }
    }
    void printWeightedGraph()
    {
        for(auto it:myMapWeight)
        {
            cout<<it.first<<" : ";
            for(auto ij:myMapWeight[it.first])
            {
                cout<<ij.first<<"("<<ij.second<<") ";
            }
            cout<<endl;
        }
    }
    void bfs(int source)
    {
        queue<int> q;
        set<int> visited;
        visited.insert(source);
        q.push(source);
        while(q.empty()==false)
        {
            int cur=q.front();q.pop();
            cout<<cur<<" ";
            for(auto it:myMap[cur])
            {
                if(visited.find(it)==visited.end())
                    {
                        q.push(it);
                        visited.insert(it);
                    }
            }
        }
    }

    void dfs(int source)
    {
        set<int> visited;
        dfs(source,visited);
    }
    void shortestUsingBfs(int source)
    {
        map<int,int> distance;
        distance[source]=0;
        queue<int> q;
        q.push(source);
        set<int> visited;
        visited.insert(source);
        while(q.empty()==false)
        {
            int cur=q.front();q.pop();
            for(auto it:myMap[cur])
            {
                if(visited.find(it)==visited.end())
                {
                    visited.insert(it);
                    distance[it]=distance[cur]+1;
                    q.push(it);
                }
            }
        }


        cout<<"printing distance of all nodes from source("<<source<<")\n";
        for(auto it:myMap)
        {
            cout<<"distance of "<<it.first<<" from "<<source<<" is "<<distance[it.first]<<endl;
        }
    }
    bool cycleDetectionBfs(int source)
    {
        set<int> visited;
        map<int,int> parent;
        queue<int> q;
        q.push(source);
        visited.insert(source);
        parent[source]=source;
        while(q.empty()==false)
        {
            int cur=q.front();q.pop();
            for(auto it:myMap[cur])
            {
                if(visited.find(it)==visited.end())
                {
                    visited.insert(it);
                    q.push(it);
                    parent[it]=cur;
                }
                else
                {
                    if(it!=parent[cur])
                        return true;
                }
            }
        }
        return false;
    }
    bool cycleDetectionDirectedGraphDfs(int source)
    {
        map<int,bool> visited;
        map<int,bool> inStack;
        for(auto it:myMap)
        {
            if(visited[it.first]==false)
            {
                bool isCyclePresent=dfsHelper(it.first,visited,inStack);
                if(isCyclePresent)
                    return true;
            }
        }
        return false;
    }
    void dijkstra(int source)
    {
        set<pair<int,int>> hold;
        map<int,int> distance;
        for(auto it:myMapWeight)
        {
            for(auto ij:myMapWeight[it.first])
                distance[ij.first]=1e6;
        }
        distance[source]=0;
        hold.insert(make_pair(0,source));
        while(hold.size()!=0)
        {
            pair<int,int> Node=*(hold.begin());hold.erase(Node);
            int curDist=Node.first;
            int curNode=Node.second;
            for(auto it:myMapWeight[curNode])
            {
                auto ij=*(hold.find(make_pair(distance[it.first],it.first)));
                if(distance[it.first]>it.second+curDist)
                {
                    if(ij!=*(hold.end()))
                        hold.erase(ij);
                    distance[it.first]=it.second+curDist;
                    hold.insert(make_pair(distance[it.first],it.first));
                }
            }
        }

        cout<<"\nprinting distance from source("<<source<<")\n";
        for(auto it:distance)
        {
            cout<<"distance of "<<it.first<<" from "<<source<<" is "<<it.second<<endl;
        }
    }
    class myCompare
    {
    public:
        bool operator()(pair<int,int> p1,pair<int,int> p2)
        {
            if(p1.second>p2.second)
                return true;
            return false;
        }
    };
    void dijkstraUsingPriorityQueue(int source)
    {
        typedef pair<int,int> weightedEdge;
        map<int,int> distance;
        map<int,bool> visited;
        for(auto it:myMapWeight)
        {
            distance[it.first]=INT_MAX;
            visited[it.first]=false;
        }
        distance[source]=0;
        priority_queue<weightedEdge,vector<weightedEdge>,myCompare> pq;
        pq.push(make_pair(source,0));


        while(pq.empty()==false)
        {
            weightedEdge curEdge=pq.top(); pq.pop();
            if(visited[curEdge.first]==true)
                continue;
            visited[curEdge.first]=true;
            distance[curEdge.first]=curEdge.second;
            for(auto it:myMapWeight[curEdge.first])
            {
                if(visited[it.first]==false)
                {
                    distance[it.first]=it.second+curEdge.second;
                    pq.push(make_pair(it.first,distance[it.first]));
                }
            }
        }

        for(auto it:distance)
            cout<<"distance of "<<it.first<<" from "<<source<<" is "<<distance[it.first]<<endl;

    }
    graph transpose()
    {
        graph g;
        for(auto i:myMap)
        {
            for(auto j:myMap[i.first])
                g.addEdge(j,i.first,false);
        }
        return g;
    }
    bool kosaRaju(int n)//strongly connected graph
    {
        set<int> visited;
//        for(auto it:myMapWeight)
//        {
//            visited[it.first]=false;
//            for(auto ij:myMapWeight[it.first])
//                visited[ij.first]=false;
//        }
    for(auto it:myMap)
    {
        if(visited.find(it.first)==visited.end())
        {
            dfs(it.first,visited);
            if(visited.size()!=n)
                return false;
        }
    }
    visited.clear();
    *this=transpose();
    for(auto it:myMap)
    {
        if(visited.find(it.first)==visited.end())
        {
            dfs(it.first,visited);
            if(visited.size()!=n)
                return false;
        }
    }
    return true;
    }

    int kruskal()
    {
        typedef tuple<int,int,int> Edge;
        vector<Edge> edgeList;
        for(auto it:myMapWeight)
        {
            int src=it.first;
            for(auto ij:myMapWeight[it.first])
            {
                int dest=ij.first;
                int cost=ij.second;
                Edge newEdge=make_tuple(src,dest,cost);
                edgeList.push_back(newEdge);
            }
        }
        compare c;
        UnionSet edgeset(myMapWeight.size());
        sort(edgeList.begin(),edgeList.end(),c);
        int cost=0;
        for(int i=0;i<edgeList.size();i++)
        {
            int src=get<0>(edgeList[i]);
            int dest=get<1>(edgeList[i]);
            int weig=get<2>(edgeList[i]);
            if(edgeset.isSameSet(src,dest))
                continue;
            else
            {
                edgeset.make_set(src,dest);
                cost+=weig;
            }
        }
        return cost;
    }
    bool cyclicUsingUnion()
    {
        UnionSet u(myMap.size());
        map<int,bool> visited;
        for(auto it:myMap)
        {
            visited[it.first]=true;
            for(auto ij:myMap[it.first])
            {
                if(visited[ij]==false)
                {
                    if(u.isSameSet(it.first,ij))
                        return true;
                    u.make_set(it.first,ij);
                }
            }
        }
        return false;
    }
    class forPrim{
    public:
        bool operator()(pair<int,int> &p1,pair<int,int> &p2)
        {
            if(p1.second>p2.second)
                return true;
            return false;
        }
    };
    int prims(int source)
    {
        vector<pair<int,int>> v;
        map<int,int> key;
        map<int,bool> visited;
        for(auto it:myMapWeight)
        {
            key[it.first]=1e6;
            visited[it.first]=false;
        }
        key[source]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,forPrim> pq;
        pq.push(make_pair(source,0));
        while(pq.empty()==false)
        {
            pair<int,int> node=pq.top();pq.pop();
            int curKey=node.second;
            int curNode=node.first;
            if(visited[curNode]==true)
                continue;
            visited[curNode]=true;
            for(auto it:myMapWeight[curNode])
            {
                if(visited[it.first]==false)
                {
                    if(key[it.first]>it.second)
                    {
                        key[it.first]=it.second;
                        pq.push(make_pair(it.first,key[it.first]));
                    }
                }
            }
        }
        int cost=0;
        for(auto it:key)
            cost+=it.second;
        return cost;
    }
    bool pathBetweenTwoVertex(int a,int b)
    {
        set<int> visited;
        dfs(a,visited);
        if(visited.find(b)==visited.end())
            return false;
        return true;
    }
};

int main()
{
    graph g;
    g.addEdge(1,2,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    g.addEdge(3,6,false);
    g.addEdge(5,6,false);
    g.addEdge(5,4,false);
    cout<<g.pathBetweenTwoVertex(1,6);

}
