#include<iostream>
#include<sstream>
using namespace std;

int permute(string s,int & count,string prefix=""){
   if(0==s.size()){
   	cout<<prefix<<endl;
   	count++;
   	return count;
   }	

   for(int i=0; i<s.size();i++){
   	  string s2= s.substr(0,i)+s.substr(i+1);
   	  stringstream ss;
   	  ss<<(s[i]); 		
      permute(s2,count,prefix+ss.str());
   }
   return count;
}

int main(){
	string s;
	cout<<"Enter String";
	cin>>s;
	int permutations=0;
	cout<<"Total "<<permute(s,permutations)<<" permutations are possible";
	return 0;
}