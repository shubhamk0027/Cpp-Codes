#include <iostream>
using namespace std;
class tree{
public:
    int data;
    tree* left;
    tree* right;
    tree(int a)
    {
        this->data=a;
        this->left=NULL;
        this->right=NULL;
    }
};
tree* createBt()
{
    int a;
    cin>>a;
    if(a==-1)
        return NULL;
    tree* root=new tree(a);
    root->left=createBt();
    root->right=createBt();
}
class isBst
{
public:
    int sze;
    bool b;
};
isBst largestBst(tree*&root)
{
    isBst ans;
    if(root->left==NULL && root->right==NULL)
    {
        ans.sze=1;
        ans.b=true;
        return ans;
    }
    isBst leftse=largestBst(root->left);
    isBst rightse=largestBst(root->right);
    if(leftse.b==true && rightse.b==true)
    {
        if(root->left->data <= root->data && root->right->data >= root->data)
        {
            ans.sze=leftse.sze+rightse.sze+1;
            ans.b=true;
        }
        else
        {
            ans.sze=max(leftse.sze,rightse.sze);
            ans.b=false;
        }
    }
    else if(leftse.b==false && rightse.b==true)
    {
        ans.sze=rightse.sze;
        ans.b=false;
    }
    else if(rightse.b==false && leftse.b==true)
    {
        ans.sze=leftse.sze;
        ans.b=false;
    }
    else
    {
        ans.sze=max(leftse.sze,rightse.sze);
        ans.b=false;
    }
    return ans;
}
int main()
{
    tree* root=createBt();
    cout<<largestBst(root).sze<<endl;
}
