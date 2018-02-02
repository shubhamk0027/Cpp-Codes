//Knights Tour Problem

#include<iostream>
#include<vector>

using namespace std;

//iostream has exit 0 function
//note that permission to use the output file or to mainpulate the ouutput file by the cmd prompt is using namespace std;
//when that program is opened in another windwo means a.out/a.exe is running
//return ->0<-  u
//when we used the count  then the number of calls detected was 182 lakhs at the start which rreached to 1282 crores or even more
//if we take the short inatead of int everywhere then the time of execution reduces!!!!!
//As the level of language decreses the time of compilation reduces
void print(vector<vector <int> > board){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
           cout<<board[i][j]<<" ";
           cout<<"\n";
        }
}

vector<vector<int > > dir ={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int count=0;
char ch;
void KnightsTour(vector<vector <int> > & board, int row=0, int col=0, int pos=2){
   count++;
 
   if(pos==65){
    	print(board);
    	cout<<"Total calls: "<<count;
    	exit(0); //importatnt to close the program!!
    	return;

      }

    int x,y;    
    for(int i=0; i<8;i++)
    {   x= row+ dir[i][0]; y=col+ dir[i][1];
        if(x<8 && y<8 && x>=0 && y>=0) { 
       	  if(board[x][y]==0){      //follow all the left choices
    	    board[x][y]=pos; 
    	    KnightsTour(board,x,y,pos+1);
    	    board[x][y]=0;    //unchoose
            }
              
        }
    }   
}

int main(){
	vector< vector<int> > board(8, vector<int>(8));
	board[0][0]=1;
	KnightsTour(board);
	return 0;
}