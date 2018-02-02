#include<iostream>
#include<vector>
using namespace std;


vector<vector<int> > dir={{1,0},{0,1},{-1,0},{0,-1}};
int count=0;

void print(vector<vector<int> > maze){
	int n=maze.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<maze[i][j]<<"   ";
		cout<<"\n";
	}
	cout<<"Total number of calls of the recursive function = "<<count<<"\n";
    }

bool route(vector<vector<int> > &maze,int row=0,int col=0, int pos=2){
	count++;
	if(maze[maze.size()-1][maze.size()-1]!=1){
		print(maze);
		return true;
	    }

    int x,y;  
    for(int i=0; i<4; i++){
    	x=row+dir[i][0]; y=col+dir[i][1];
        if(x<maze.size() && y<maze.size() && x>=0 && y>=0 && maze[x][y]==1){
        	maze[x][y]=pos;//-1 means a visited node.
            route(maze,x,y,pos+1);
            	
            maze[x][y]=1;//unchoose
        	}
        }
        return false;
    }

int main(){
 vector<vector<int> > maze={
 	{1,0,0,0,0,0},
    {1,1,0,0,0,0},
    {0,1,1,1,1,0},
    {0,0,1,1,1,0},
    {0,0,0,1,1,0},
    {0,0,0,1,1,1}};
 route(maze);
 return 0;   
}