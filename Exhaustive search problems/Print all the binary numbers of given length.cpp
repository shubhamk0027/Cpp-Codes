#include<iostream>

using namespace std;

void printBinary(int n,string prefix=""){
	if(n==0){
		cout<<prefix;
		return;
      	}
	printBinary(n-1,prefix+"0");
    printBinary(n-1,prefix+"1");	  
 
}

int main(){

	cout<<"Enter the binary sequence length";
	int n;
	cin>>n;
	printBinary(n);

	return 0;
}