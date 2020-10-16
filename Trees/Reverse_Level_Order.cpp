/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int mid=0,maxl=0;
 
 void countm(TreeNode* A,int l){
     TreeNode* B=A;
     if(B->left!=NULL){
         countm(B->left,l+1);
     }
     if(B->right!=NULL){
         countm(B->right,l+1);
     }
     maxl=max(maxl,l);
 }
 
 void func(TreeNode* A,int l,vector<vector<int>> &v){
     TreeNode* B=A;
     v[l].push_back(B->val);
     if(B->left!=NULL){
         func(B->left,l+1,v);
     }
     if(B->right!=NULL){
         func(B->right,l+1,v);
     }
 }
 
vector<int> Solution::solve(TreeNode* A) {
    vector<vector<int>> v;
    vector<int> ans;
    ans.clear();
    v.clear();
    ans.clear();
    countm(A,0);
    v.resize(maxl+1);
    func(A,0,v);
    for(int i=maxl;i>=0;i--){
        for(auto it=v[i].begin();it!=v[i].end();it++){
            ans.push_back(*it);
        }
    }
    return ans;
}
