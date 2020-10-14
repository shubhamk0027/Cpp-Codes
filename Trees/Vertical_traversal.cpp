//If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal of //tree comes first in the output.
//Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the //nodes on the rightmost vertical line.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int mid=0,maxl=0,maxr=0;
 
 void countm(TreeNode* A,int l,int r){
     TreeNode* B=A;
     if(B->left!=NULL){
         countm(B->left,l+1,r-1);
     }
     if(B->right!=NULL){
         countm(B->right,l-1,r+1);
     }
     maxl=max(maxl,l);
     maxr=max(maxr,r);
 }
 
 void func(TreeNode* A,int l,int r,vector<vector<int>> &v){
     TreeNode* B=A;
     if(l>=0){
         v[mid-l].push_back(B->val);
     }
     else{
         v[mid+r].push_back(B->val);
     }
     if(B->left!=NULL){
         func(B->left,l+1,r-1,v);
     }
     if(B->right!=NULL){
         func(B->right,l-1,r+1,v);
     }
 }
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> v,ans;
    v.clear();
    countm(A,0,0);
    int sz=maxl+maxr+1;
    v.resize(sz);
    mid=maxl;
    func(A,0,0,v);
    v.resize(sz);
    for(auto it=v.begin();it!=v.end();it++){
            vector<int > k=*it;
            if(k.size()!=0)
                ans.push_back(*it);
            //for(auto m=k.begin();m!=k.end();m++){
              //  cout<<*m<<" ";
            //}
    }
    return ans;
}
