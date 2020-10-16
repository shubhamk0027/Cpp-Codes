#include <stdio.h>
#define SIZE 1000
int front=-1;
int rear=-1;
int array[SIZE];
void push(int data)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        array[rear]=data;
        return;
    }
    if((rear+1)%SIZE==front)
    {
        printf("Queue is full!");
        return;
    }
    rear=(rear+1)%SIZE;
    array[rear]=data;
}
void pop()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is already empty!");
        return;
    }
    if(front==rear)
    {
        front=rear=-1;
        return;
    }
    front=(front+1)%SIZE;
}
int frontElement()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is already empty!");
        return;
    }
    return array[front];
}
int main()
{
    push(2); push(3); push(5);
    printf("%d\n",frontElement());
    pop();
    printf("%d\n",frontElement());
}
