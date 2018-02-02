#include<iostream>
#include<sstream>

#include<vector>

using namespace std;
void Permute(string s, string prefix=""){
   if(s.size()==0){
   	cout<<prefix<<"\n";
   	return;
   }

   for(int i=0; i<s.size();i++){
   	stringstream ss;
   	ss<<s[i];
   	Permute(s.substr(0,i)+s.substr(i+1),prefix +ss.str());
   }

}


void combinationHelper(string s, int num, string prefix){
  if(num==0)
  {
  	cout<<"New Combination permutations-";
    Permute(prefix);
  	return;
  }
  for(int i=0; i<s.size()-num+1;i++)
  { 
  	 stringstream ss;
  	 ss<<s[i];
     combinationHelper(s.substr(i+1),num-1,prefix+ss.str());
  }

}


void combinations(string s, int num){
vector<int> v(26);
string s2;
for(int i=0; i<s.size(); i++){
	v[s[i]-'a']++;
	if(v[s[i]-'a']==1)
     s2.push_back(s[i]);
}
combinationHelper(s2, num,"");

}


int main(){

	cout<<"Enter String  and number(Make Sure the strign  you are entering is in small case";
	string str;
	int num;
	cin>>str>>num;
	combinations(str,num);
	return 0;
}