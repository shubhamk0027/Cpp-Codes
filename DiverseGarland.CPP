#include<iostream>
using namespace std;
char getC(char a,char b){
if(a=='R'){
    if(b=='G') return 'B';
    if(b=='B') return 'G';
    if(b=='R') return 'B';
}
else if(a=='G'){
    if(b=='G') return 'B';
    if(b=='B') return 'R';
    if(b=='R') return 'B';
}
else{
    if(b=='B') return 'G';
    if(b=='R') return 'G';
    if(b=='G') return 'R';
}
return 'R';
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            if(i+2<n){
                s[i+1]=getC(s[i],s[i+2]);
                count++;
            }
            else{
            count++;
            }
        }
    }
    cout<<count<<endl;
return 0;
}
