long arrayManipulation(int n, vector<vector<int>> queries) {
int *Ans=new int[n+1]();
for(int i=0;i<queries.size();i++){
    vector<int> query=queries[i];
    Ans[query[0]-1]+=query[2];
    if(query[0]<=n){
        Ans[query[1]]-=query[2];
    }
    
}
long max=0;
    long x=0;
for(int i=0;i<=n;i++){
    x=x+Ans[i];
    if(x>max)
        max=x;
}
    return max;

}
/*
It Stores Ranged Data on an array using increment and decrement only(ie. no need to increment each value step by step can change only at points where increment dec happens.
Then a loop is run to Modify all values
Init: A[0,0,0,0,0,0]
range(3,5),(2,4) Increment=1,2 respectively
Operate A[0,0,1,0,0,-1]
Operate2 A[0,2,1,0,-2,-1]
Getresult A=[0,2,3,3,1,0]*/
