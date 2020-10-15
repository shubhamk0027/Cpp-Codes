#include <iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    int ht;
};
int heightOfTree(node *temp)
{
    if(temp==NULL)
        return 0;
    return temp->ht;
}
node* rightRotate(node *y)
{
    node *x=y->left;
    node *T2=x->right;

    //performing rotation
    x->right=y;
    y->left=T2;

    y->ht=max(heightOfTree(y->left),heightOfTree(y->right))+1;
    x->ht=max(heightOfTree(x->left),heightOfTree(x->right))+1;
    return x;
}
node* leftRotate(node *z)
{
    node *y=z->right;
    node *T2=y->left;
    //performing operations
    z->right=T2;
    y->left=z;

    z->ht=max(heightOfTree(z->left),heightOfTree(z->right))+1;
    y->ht=max(heightOfTree(y->left),heightOfTree(y->right))+1;

    return y;
}
int getBalance(node *root)
{
    if(root==NULL)
        return 0;
    return heightOfTree(root->left)-heightOfTree(root->right);
}
node *insert(node *root,int key)
{
    if(root==NULL)
    {
        node *temp=new node;
        temp->val=key;
        temp->left=temp->right=NULL;
        temp->ht=1;
        return temp;
    }
    if(key < root->val)
    {
        root->left=insert(root->left,key);
    }
    else
        root->right=insert(root->right,key);
    root->ht=max(heightOfTree(root->left),heightOfTree(root->right))+1;

    int balance=getBalance(root);
    if(balance > 1 && key < root->left->val)
        root=rightRotate(root);
    if(balance > 1 && key > root->left->val)
    {
        root->left=leftRotate(root->left);
        root=rightRotate(root);
    }
    if(balance < -1 && key > root->right->val)
        root=leftRotate(root);
    if(balance < -1 && key < root->right->val)
    {
        root->right=rightRotate(root->right);
        root=leftRotate(root);
    }
    return root;
}
void preOrder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    preOrder(root);
}

