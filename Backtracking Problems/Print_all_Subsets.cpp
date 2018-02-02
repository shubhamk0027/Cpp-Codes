#include<iostream>
#include<vector>

using namespace std;


void combinations(vector<int> v, int num,vector<int> prefix){
 if(num==0){
 	cout<<"{ ";
 	for(int i=0; i<prefix.size();i++)
 		cout<<prefix[i]<<" ";
 	cout<<"}\n";
 	return;
    }
    prefix.push_back(0);
   for(int i=0; i<v.size()-num+1;i++){
      vector<int> newv(v.begin()+i+1,v.end());
      prefix[prefix.size()-1]=(v[i]);
      combinations(newv, num-1,prefix);
   }
}

void Subsets(vector<int > v,int num){
   if(num==0)
   	   return;
   vector<int> prefix;
   combinations(v,num,prefix);
   Subsets(v,num-1);
}

int main(){
	vector<int> v;   
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    Subsets(v,v.size());
    return 0;
}