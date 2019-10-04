void iterInorder(Node *root){
    Node *p=root;
    stack<Node> s;
    while(true){
        while(p!=NULL){
            s.push(*p);
            p=p->left;
        }
        if(s.empty()) break;
        cout<<s.top().data<<"-->";
        p=s.top().right;
        s.pop();
    }
}
