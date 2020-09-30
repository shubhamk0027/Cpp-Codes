
#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>

using namespace std;
const ll mod =1e9+7;
const int N =2e6+1;

// Manchar Algorithm: For finding the longest palindromic substring->
// Naive-> for i...j check if pad in O(n) -> O(N3)
// Optimized->
// 		consider i as the center point expand to the left and right O(N2)T & O(1)S
//		dp-> cal is [i][j] from (i+1)(j-1) // O(N2) time and space
// 		Using Palindromc Tree
//		Using Suffix Tree (Complex Expected O(N))
// 		Manachers Algorithm O(N)

// Manacher Algo->
// Convert the string from len N to len 2*N+1 for tackling odd and even len pads
// lps[i] (longest palindromic substring centered around i)
// Observation: In 0 based index system in such string 
//		if i is even then lps[i] will be even(even len pad)
// 		if i is odd then lps[i] will be odd and >1(odd len pad)
// Property-> 
//		lps[i] will be symm around j if j is a center and i..j is a part of the pad
//		If somehow we can reduce the calculation of such lps[i] and using this
//		property and simply assign the values from its left part then it will be O(N)
// Example->
// 	string		| a | b | a | b | a |  b  |  a  |
// 	indexes		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
// 	lps[i]		0 1 0 3 0 5 0 7	0 5 0  3  0  1  0	

string s,res;
int p[N];

void manacher(){
	// p[i] stores the length of the longest palindrome with center i
	string ss="|"; 
	// altering the string to tackle odd and even length palindromes, since center might not always be a character!
	for(auto x:s) ss.pb(x),ss.pb('|');
	// the optimization done in manacher was-> 
	// once we find a palindrome of length l at p[i] we try to efficintly calcuate the p[i+1] from it by avoiding visiting all the characters from the i+1 on both sides. This optimization is done by find the next center of expansion!

	// set m and r
	int m=0,r=0;
	for(int i=1;i<ss.size();i++){
		// adjust p[i] to an optimum value
		p[i]=(i<r)?min(r-i,p[m-(i-m)]):0;
		// try expanding around i
		while(i-p[i]-1>=0 && ss[i+p[i]+1]==ss[i-p[i]-1]) p[i]++;
		// adjust m and r
		if(i+p[i]>r) r=i+p[i],m=p[i];
	}

	int mx=0;
	for(int i=1;i<ss.size();i++) if(mx<p[i]) {
		mx=p[i];
		// set index to its starting point i-len+1
		// half it to get the start in org string
		res=s.substr((i-p[i]+1)/2,p[i]);
	}
}

int main() {
	cin>>s;
	manacher();
	cout<<res.size()<<"\n";
	cout<<res;
	return 0;
}

