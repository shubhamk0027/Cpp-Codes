void levelOrderTraversal(node *root){
    node *p=root;
    queue<node> q;
    cout<<p->data<<endl;
    q.push(*(p->left));
    q.push(*(p->right));
    while(!q.empty()){
    cout<<q.front().data<<endl;
    if(q.front().left!=NULL)
        q.push(*(q.front().left));
    if(q.front().right!=NULL)
        q.push(*(q.front().right));
    q.pop();
    }



//Geeks for geeks method
Print left then print right

void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 
  
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
