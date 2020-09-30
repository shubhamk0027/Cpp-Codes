//Morris Traversal
void MorT(struct tNode *root){
    if(root==NULL) return;
    //if root doesnot have left child
    while(root!=NULL){
    if(root->left==NULL){
        printf("%d,",root->data);
        root=root->right;
    }
    else{
        struct tNode *q=root->left;
        while(q->right!=NULL && q->right!=root)
            q=q->right;
        if(q->right==NULL)
          {  q->right=root;
        root=root->left;}
        else { 
                q->right = NULL; 
                printf("%d ", root->data); 
                root = root->right; 
            }
    }}
}
//Inorder Traversal Without recursion and stack
