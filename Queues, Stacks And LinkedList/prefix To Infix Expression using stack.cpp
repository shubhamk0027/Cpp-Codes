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
int preToIn(string a)
{
    stack<int> s;
    for(int i=a.length()-1;i>=0;i--)
    {
        if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/')
            s.push(a[i]-'0');
        else
        {
            int op1=s.top(); s.pop();
            int op2=s.top(); s.pop();
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
    int res=preToIn(a);
    cout<<res;
}
