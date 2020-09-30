#include<bits/stdc++.h>

using namespace std;
const int N =2e5;
int to[N], lps[N];
string pattern,text;

/*
If pattern not found!
P => ...cedcecedce|d|...
T =>    cedcecedce|f|
P => ...cedcecedce|d|... we will move to c with the help of e
T =>         cedce|c|
P => ...cedcecedce|d|... if lps[e]=2 j->2
T =>            ce|d|
clearly keeping length will be benifical not by keeing the postion to which it should jump if not equal!
else while loop will not be terminated and we need to specify other conditions as well
and differnce between the len will not be 0 for two cases-> when no len exist and when len is itself 0

If pattern found!
     the algo remains the same as it was for building the lps array!
P => ...cedcecedced|c|...
T =>    cedcecedced
P => ...cedcecedced|c|...
T =>            ced|c|ecedced
writing like this literally works damn!!!
*/

void kmp(){
    int len=0; 
    for(int i=1;i<pattern.size();i++){
        if(pattern[len]==pattern[i]) lps[i]=++len;
        else{
            while(len && pattern[len]!=pattern[i]) len=lps[len-1];
            if(pattern[len]==pattern[i]) lps[i]=++len;
        }
    }
    int j=0;
    for(int i=0;i<text.size();i++){
        if(text[i]==pattern[j]) j++;
        else{
            while(j && text[i]!=pattern[j]) j=lps[j-1];
            if(text[i]==pattern[j]) j++;
        }
        if(j==pattern.size()){
            cerr<<"\nPattern found at index"<<i-pattern.size()+1;
            j=lps[j-1]; 
        }
    }
}



int main(){
    text ="cedcecedcedcecedced";
    pattern ="cedcecedced";
    kmp();
    return 0;
}


/*
void kmp2(){
    lps -> longest prefix that is also a suffix, gfg or other sites use the same trick
    but here i am keeping the index from where the program should start the search in case
    the current character does not matches instead of the length till i!
    j=-1 implies that the character does not matches
    j=0 implies that this character matches but no initial prefix=suffix
    but this will not work simply, it will need more modifications why?
    if the character does not matches then kmplen[i] returns the index from where 
    it should start comparing the to character in the string, but that unmatched character is not
    considered in the 
    int j=0;
    for(int i=1;i<pattern.size();i++) {
        if(j==-1 || pattern[i]==pattern[j]) j++;
        else if(pattern[i]==pattern[i-1]) to[i]=to[i-1];
        else j=-1; 
        if(j!=-1) to[i]=j;
    }
    to[pattern.size()]=min(int(pattern.size()-1),j);
    cout<<"to: ";
    for(int i=0;i<pattern.size();i++) cout<<"("<<pattern[i]<<"|"<<to[i]<<")";
    //Searching....
    j=0;
    for(int i=0;i<text.size();i++){
        cerr<<i<<"->";
        if(text[i]==pattern[j]) j++;
        else j=to[j];
        if(j==pattern.size()) {
            cerr<<"\npattern found at index "<<i;
            j=to[j];
        }
        cerr<<j<<"\n";
    }
}
*/