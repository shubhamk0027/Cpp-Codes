#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head;
void push(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
int front()
{
    if(head==NULL)
    {
        printf("queue is empty!");
        return -1;
    }
    else
        return head->data;
}
void pop()
{
    if(head==NULL)
        printf("queue is empty!");
    else
    {
        struct node* temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    head=NULL;
    printf("%d\n",front());
    push(5);push(6);push(7);
    printf("%d\n",front());
    pop();
    printf("%d",front());
}
