/*8Queens problem
In this problem you have to find where to place 8 queens such that no queen can cancel each other in a chess board

Native algorithm
 For each board square
     place a queen there
     try to place the rest of the queens
     unplace the queen

Size of the sample space-64*.. many  and many


0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
/*
0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
#include<iostream>
#include<vector>

using namespace std;

int count=0;
void print(vector<vector<int> > board){
	int n=board.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
	count++;

}

vector<vector<int> > updateboard(vector<vector<int> > board,int row, int col){
    int n=board.size();
    board[row][col]=1;
    //update row elements;
    for(int i=0; i<n;i++){
    	if(board[row][i]!=1)
    		board[row][i]=0;	
    //update col elements //for(int i=0; i<n;i++)
    	if(board[i][col]!=1)
    		board[i][col]=0;
    }

    //diagonals upper half left
    int i=row-1, j=col+1;
    while(i>=0&&j<n){
      if(board[i][j]!=1) board[i][j]=0;
      i--;
      j++;
    }
    //lower left
    i=row+1, j=col+1;
    while(i<n&&j<n){
      if(board[i][j]!=1) board[i][j]=0;
      i++;
      j++;
    }
    //upper right
    i=row-1, j=col-1;
    while(i>=0&&j>=0){
      if(board[i][j]!=1) board[i][j]=0;
      i--;
      j--;
    }
    //lower right
    i=row+1, j=col-1;
    while(i<n&&j>=0){
      if(board[i][j]!=1) board[i][j]=0;
      i++;
      j--;
    }
    return board;

}
    /*//update left diagonal
    int i,j;
    if(row<col){
    	//understand ths code caarefully
    	 j=n-1;//since col is greater
    	 i=(j-col);
    	while(i<n){
    		if(board[i][j]!=1)  board[i][j]=0;
    	i++;j--;
    	 i=0;
    	 j=col-row;
    	while(j<n) 
            if(board[i][j]!=1)  board[i][j]=0;
    	i++;j++;
    	}
    }      		
    else{
         i=0;
    	 j=row+col;
    	while(i<n){
    		if(board[i][j]!=1)  board[i][j]=0;
    	i++;j--;}
    	 j=0;
    	 j=row-col;
    	while(j<n) 
            if(board[i][j]!=1)  board[i][j]=0;
    	i++;j++;
    	}
     }
	return board;
	*/

void EightQ (vector<vector<int> > board, int col=0){
if(col==board.size()){
	print(board);
	cout<<"\n\n";
	return;
    }
    //01 is octal
 for(int i=0 ;i<board.size(); i++){
    if(board[i][col]!=0){
      EightQ(updateboard(board,i,col),col+1);
    }       
   }
}

/*
for(int i=0; i<board.size();i++){
 if(board[col][i]==-1){
    EightQ(board,col+1) and update......if wrong descision then;
 remove the change->difificult
 Here we say that all the places that have been filled with -1 are available. 
 Starting form first column we go through tht whole 8 indexes in the column and of that space has a value of -1 the we will choose that else 
 try next row.
 For this we need to choose, follow and then unchoose. Here the choosing and the unchoosing matters because since there are 64 ints so creating 
 a vector each time will increase thee space an dtime complexity very much so we need to do the choosing, updations and the unchoosing on the same
 vector. So its the real backtracking. In the last programs we created a new vector but there the size was less so cresting them didnt take much
 time but here it is taking much time!!!!*/

int main(){
	vector<vector<int> > board(8,vector<int>(8));
	//by default 0 assigned
	for(int i=0; i<8; i++)
		for(int j=0; j<8;j++)
           board[i][j]=2;
	EightQ(board);
	cout<<"Total Possibilities: "<<count;
	return 0;/
}


//Final key i backtracking->
/*In back tracking we need to keep the track of the last path. But that does not means that we need to retrace each path bhy our 
calculation! It will backtrack automatically by recursion. Thats why almost all backtracking algos use recursion. Recursion will automatically retace.
*/

