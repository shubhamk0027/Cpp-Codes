/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* root) {
    if(root == NULL)
        return root;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    root->left = invertTree(r);
    root->right = invertTree(l);
    return root;
}
