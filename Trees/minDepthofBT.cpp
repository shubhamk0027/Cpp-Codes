/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int maxd=INT_MAX;
 int func(TreeNode*A , int d){
     int a=INT_MAX,b=INT_MAX;
     if(A->left!=NULL){
         a=func(A->left,d+1);
     }
     if(A->right!=NULL){
         b=func(A->right,d+1);
     }
     if(A->left==NULL && A->right==NULL){
         return d;
     }
     return min(a,b);
 }
 
int Solution::minDepth(TreeNode* A) {
    return func(A,1);
}
