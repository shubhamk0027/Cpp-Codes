//Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

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
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> v,ans;
    ans.clear();
    v.clear();
    ans.clear();
    countm(A,0);
    v.resize(maxl+1);
    func(A,0,v);
    int i=0;
    for(auto it=v.begin();it!=v.end();it++){
        vector<int > j,k=*it;
        if(i%2!=0 && k.size()!=0){
            for(auto m=k.begin();m!=k.end();m++){
                j.insert(j.begin(),*m);
            }
            ans.push_back(j);
        }
        else if(k.size()!=0)ans.push_back(k);
        i++;
        j.clear();
    }
    return ans;
}
