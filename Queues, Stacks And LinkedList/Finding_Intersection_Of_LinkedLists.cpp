int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//My Approach
/*Other Approach include Nested Loop :

1.Use 2 nested for loops. The outer loop will be for each node of the 1st list and inner loop will be for 2nd list

Or Mark visted flag on each elemtn of link list 1 and then see if in link list 2 tehre  is an elemnt whose flag is marked visted already
*/
    //Finding list lengths
    int c1=0,c2=0;
    SinglyLinkedListNode *p=head1,*q=head2;
    while(p!=NULL){
        p=p->next;
        c1++;
    }
    while(q!=NULL){
        q=q->next;
        c2++;
    }
    if(c1<c2){
        p=head1;
        q=head2;
        int k=c2-c1;
        while(k>0){
            q=q->next;
            k--;
        }
        while(p!=NULL && q!=NULL){
            if(p==q)
                return p->data;
            p=p->next;
            q=q->next;
            
        }
        
    }
    else{
        p=head1;
        q=head2;
        int k=c1-c2;
        while(k>0){
            p=p->next;
            k--;
        }
        while(p!=NULL && q!=NULL){
            if(p==q)
                return p->data;
            p=p->next;
            q=q->next;
            
        }

    }
return 0;
}
