Node* reverse(Node* head) {
    Node *p,*q,*r;
    if(head==NULL || head->next==NULL)
        return head;
    else{
        p=head;
        q=p->next;
        r=q->next;
        p->next=NULL;
        p->prev=q;
        q->next=p;
        q->prev=r;
        while(r!=NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
            q->prev=r;
        }
        return q;
        
        
    }
  return head;  
}
