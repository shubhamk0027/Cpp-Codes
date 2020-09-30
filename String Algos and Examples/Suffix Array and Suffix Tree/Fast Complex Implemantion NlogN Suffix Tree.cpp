// [1] https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english
// [2] https://brenden.github.io/ukkonen-animation/
// [3] http://ideone.com/sT8Vd1

#include<bits/stdc++.h>
using namespace std;
/*
A suffix tree T for a m-character string S is a rooted directed tree with exactly m leaves numbered 1 to m. (Given that last string character is unique in string)
    1. Root can have zero, one or more children.
    2. Each internal node, other than the root, has at least two children.
    3. Each edge is labelled with a nonempty substring of S.
    4. No two edges coming out of same node can have edge-labels beginning with the same character.
Suffix Tree is just a compressed Trie that builds in O(n) instead of O(n2)

Compressed trie: 
	edges that direct to a node having single child are combined together to form a single edge and their edge labels are concatenated. 
	each internal node at least 2 children
	at most n leaf nodes as n strings inserted
	at most 2N-1 nodes in the trie
	Space complexity: O(n) over O(n2) of a normal trie
Compressd Trie is obtained from standard trie by joining chains of single nodes. 

Application: 
    Pattern Searching
    Longest Repeated Substring O(N)
    Longest Common Substring O(N)
    Longest Palindrom in a string O(N)
    // Many more Apps: https://en.wikipedia.org/wiki/Suffix_tree#Functionality

$- Special character smallest among all the characters!
Implicit Suffix Tree: At most N nodes
	Ex for banana-> three nodes only-> banana,anana,nana (nodes without any $)
    
Normal Suffix Tree: Exactly N nodes. (with $)
	By adding special char $ at end that will not match with any of them and will make sure there are N leaf nodes
	Ex for banana..na(na$)na$
*/


void buildNaive(string s){
    // O(N2)
    for(int i=0;i<s.size();i++){
        // add(s[i..s.size()-1]) to the tree so far
    }
}

void HighlevelIntroUkkonen(string s){
    // O(N)
    // tree consists of N nodes 
    // Node 1 is added using 1st character
    // Node 2 using the second ..
    for(int i=0;i<s.size();i++)
        for(int j=0;j<i;j++){
            // find the end of path from the root labelled s[j...i] [Suffix links to speed up this!]
            // extend that path to char s[i+1], if not already there
        }
}

//Suffix links
// For an internal node v with path-label xA, where x denotes a single character and A denotes a (possibly empty) substring, if there is another node s(v) with path-label A, then a pointer from v to s(v) is called a suffix link.
// In extension j of phase i+1, we need to find the end of the path from the root labelled S[j..i] in the current tree. One way is start from root and traverse the edges matching S[j..i] string. Suffix links provide a short cut to find end of the path.

/**************Final Implemenatation***********************/
const int N =1e5+1; // a structure cant have size more than 1e6 here that!
struct SuffixTree{
	map<int,int> to[N];
	char s[N];
	const int INF=1e9;
	int len[N],fpos[N],link[N];
	int node,pos,sz,n;

	SuffixTree(string &ss){
		node=pos=n=0;
		fill(fpos,fpos+N,0); 
		fill(len,len+N,0);
		sz=1; len[0]=INF;
		for(auto c:ss) add_letter(c);
		add_letter('$');
		print();
	}

	int make_node(int _pos,int _len){
		fpos[sz]=_pos,len[sz]=_len;
		return sz++;
	}

	void go_edge(){
		while(pos>len[to[node][s[n-pos]]]){
			node=to[node][s[n-pos]];
			pos-=len[node];
		}
	}

	void add_letter(int c){
		s[n++]=c;
		pos++;
		int last=0;				// this is the node whose child can be expanded! We will always start the search with the root node.
		while(pos>0){
			go_edge();					// find the current node that is to be extended(by adding a child to it)(if needed)
			int edge = s[n-pos];		// find the corresponding edge of that node
			int & v = to[node][edge];	// find the node corresponding to the children of that node
			int t= s[fpos[v]+pos-1];	// the last character of the old suffix which matches with this one
			if(!v){						// a new suffix is to be added!
				v=make_node(n-pos,INF);
				link[last]=node;
				last=0;
			}else if(t==c){				// already there is a suffix and that suffix lies entirely on it! (will not be extended now!)
				link[last]=node;
				return;
			}else{						// there is a suffix already present but that does not lie entirely on it!
				int u=make_node(fpos[v],pos-1);
				to[u][c]=make_node(n-1,INF);
				to[u][t]=v;		// this is done because the node that has been splitted might already has a lot of nodes attatached to it!
				fpos[v]+=pos-1;
				len[v]-=pos-1;
				last=v=link[last]=u;
			}
			if(!node) pos--;
			else node=link[node];
		}
	}

	void print(){
		for(int x=1;x<sz;x++) {
			cerr<<"[Id="<<x<<",\tS=";
			for(int i=0;i<n && i<len[x];i++) cerr<<s[i+fpos[x]];
			cerr<<", \tFpos="<<fpos[x]<<",\tLen="<<len[x]<<" "<<link[x]<<"\n";
		}
	}
};


int main() {
	string s="abcabdeabx";
	SuffixTree St(s);
	return 0;
}