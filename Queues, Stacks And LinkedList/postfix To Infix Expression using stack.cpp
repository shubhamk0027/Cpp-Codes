#include <iostream>
#include <stack>
using namespace std;
int expression(int op1,int op2,char a)
{
    if(a=='+')
        return op1+op2;
    else if(a=='-')
        return op1-op2;
    else if(a=='*')
        return op1*op2;
    else
        return op1/op2;
}
int postToIn(string a)
{
    stack<int> s;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/')
            s.push(a[i]-'0');
        else
        {
            int op2=s.top(); s.pop();
            int op1=s.top(); s.pop();
            int res=expression(op1,op2,a[i]);
            s.push(res);
        }
    }
    return s.top();
}
int main()
{
    string a;
    cin>>a;
    int res=postToIn(a);
    cout<<res<<endl;
}
