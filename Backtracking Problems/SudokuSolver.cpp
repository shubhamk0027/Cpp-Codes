/*
8 0 6 0 0 3 0 9 0
0 4 0 0 1 0 0 6 8
2 0 0 8 7 0 0 0 5
1 0 8 0 0 5 0 2 0
0 3 0 1 0 0 0 5 0
7 0 5 0 3 0 9 0 0
0 2 1 0 0 7 0 4 0
6 0 0 0 2 0 8 0 0
0 8 7 6 0 4 0 0 3

*/

#include<iostream>
#include<vector>
using namespace std;


//using backttracking
//Here unchoosing is weasy so we will not pass another 2d vector
bool issafe(vector< vector<int> > Sudoku,int row, int col, int num){
     int n=Sudoku.size();
     //applying rules
     //checking int the column and the row
     for(int i=0; i<n; i++){
     	if(Sudoku[i][col]==num||Sudoku[row][i]==num)
     		return false;	
     }
     //checking in the box
     row=(row/3)*3;
     col=(col/3)*3;

     for(int i=0; i<3; i++)
     	for(int j=0; j<3; j++)
     		if(Sudoku[i+row][j+col]==num)
     			return false;

     return true;
}


void print(vector< vector<int> > Sudoku){
	int n=Sudoku.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<Sudoku[i][j]<<" ";
		cout<<endl;
	}
}

int count=0;
char c;

void SolverHelper(vector<vector<int> > & Sudoku,int row,int col,vector<int> & availableval)
{   count++;
    
    if(row==Sudoku.size()){
	    //cout<<"ending function";
	  	print(Sudoku);
		cout<<"Total number of function calls: "<<count; 
		return; 
	    }
    //choose that choice C. Note that by the beow coe we are choosing the choice only. Since neither row,9 is a choice nor the filled block is
    // Here we are only validating that choice(means is it really a choice? Later we will decide wether the choice is right or not)
    //Difference is big understand that
    if(col==Sudoku.size()){ 
    	//cout<<"col==size\n";
    	//cout<<"Calling Next row\n";
    	//not a choice
        vector<int> availablevalnew(Sudoku.size());
    	SolverHelper(Sudoku,row+1,0,availablevalnew);
    	//passing the old 
    	availableval=availablevalnew;
    	return;
    	}
    if(col==0){//means time to initialize
    //cout<<"time to initialize the one d vector\n";
    for(int i=0;i<Sudoku.size();i++){
       if(Sudoku[row][i]!=0)
       	 availableval[Sudoku[row][i]-1]=1;
       }
    }
    if(Sudoku[row][col]!=0){
    //cout<<"Some other element already present\n";
   	//cout<<"Calling Next Column\n";
   	//not a choice
   	//means the block is filled and the number with fills it is also not allowed
   	//<<-IMP!!!!->>and if that number is also available in the availableval then this means that we need to return to the point where theat value is assigned
   	    SolverHelper(Sudoku, row, col+1,availableval);
        return;
    	}	
   for(int i=0; i<Sudoku.size();i++){
    	if(availableval[i]==0){
        bool isSafe=issafe(Sudoku,row,col,i+1);
        if(isSafe){
             Sudoku[row][col]=i+1;
             availableval[i]=1;
             SolverHelper(Sudoku,row,col+1,availableval);
             availableval[i]=0;
             Sudoku[row][col]=0;
             }
        }
    }
}


void Solver(vector<vector<int> > & Sudoku){
    vector< int> availableval(Sudoku.size());
    SolverHelper(Sudoku,0,0,availableval);
}


int main(){
   vector< vector<int> > Sud={
   {0,0,0,0,0,0,0,0,0},
   {1,2,0,0,0,0,0,8,4},
   {0,3,0,0,0,0,0,7,0},
   {0,0,4,0,0,0,6,0,0},
   {0,0,0,2,0,3,0,0,0},
   {0,0,5,0,0,0,9,0,0},
   {0,0,6,0,9,0,5,0,0},
   {0,7,0,0,0,0,0,2,0},
   {0,0,0,0,5,0,0,0,0}
   };  
 
   Solver(Sud);
return 0; 
}