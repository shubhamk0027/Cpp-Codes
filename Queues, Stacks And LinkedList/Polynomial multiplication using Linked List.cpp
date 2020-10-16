#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int coeff;
    int exp;
    struct poly *next;
};
struct poly* createPoly(struct poly *start)
{
    int n;
    struct poly* ptr;
    struct poly* prePtr;
    printf("Enter number of terms\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter coeff and exponent\n");
        int coeff,exp;
        scanf("%d %d",&coeff,&exp);
        if(start==NULL)
        {
            struct poly *newNode=(struct poly*)malloc(sizeof(struct poly));
            newNode->coeff=coeff;
            newNode->exp=exp;
            newNode->next=NULL;
            start=newNode;
            prePtr=start;
        }
        else
        {
            struct poly *newNode=(struct poly*)malloc(sizeof(struct poly));
            newNode->coeff=coeff;
            newNode->exp=exp;
            newNode->next=NULL;
            prePtr->next=newNode;
            prePtr=newNode;
        }
    }
    return start;
}
void printPoly(struct poly* start)
{
    while(start->next!=NULL)
    {
        printf("%dx^%d+",start->coeff,start->exp);
        start=start->next;
    }
    printf("%dx^%d",start->coeff,start->exp);
    printf("\n");
}
struct poly* addPoly(struct poly *start1,struct poly *start2)
{
    struct poly *start3=NULL;
    struct poly *ptr1=start1;
    struct poly *ptr2=start2;
    struct poly *ptr3=start3;
    int i=0;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        struct poly *newNode=(struct poly*)malloc(sizeof(struct poly));
        int coeff,exp;
        if(ptr1->exp < ptr2->exp)
        {
            coeff=ptr2->coeff;
            exp=ptr2->exp;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp)
        {
            coeff=ptr1->coeff;
            exp=ptr1->exp;
            ptr1=ptr1->next;
        }
        else
        {
            coeff=ptr1->coeff+ptr2->coeff;
            exp=ptr1->exp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        newNode->coeff=coeff;
        newNode->exp=exp;
        newNode->next=NULL;
        if(start3==NULL)
        {
            start3=newNode;
            ptr3=newNode;
        }
        else
        {
            ptr3->next=newNode;
            ptr3=newNode;
        }
    }

    while(ptr1!=NULL)
    {
        struct poly *newNode=(struct poly*)malloc(sizeof(struct poly));
        newNode->coeff=ptr1->coeff;
        newNode->exp=ptr1->exp;
        newNode->next=NULL;
        if(start3==NULL)
        {
            start3=newNode;
            ptr3=newNode;
        }
        else
        {
            ptr3->next=newNode;
            ptr3=newNode;
        }
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        struct poly *newNode=(struct poly*)malloc(sizeof(struct poly));
        newNode->coeff=ptr2->coeff;
        newNode->exp=ptr2->exp;
        newNode->next=NULL;
        if(start3==NULL)
        {
            start3=newNode;
            ptr3=newNode;
        }
        else
        {
            ptr3->next=newNode;
            ptr3=newNode;
        }
        ptr2=ptr2->next;
    }
    return start3;
}
struct poly* multiply(struct poly* start1,struct poly* start2)
{
    struct poly* ptr1=start1;
    struct poly* ptr2;
    struct poly* start3=NULL;
    while(ptr1!=NULL)
    {
        ptr2=start2;
        struct poly* temp=NULL;
        struct poly* ptr;
        while(ptr2!=NULL)
        {
            struct poly* newNode=(struct poly*)malloc(sizeof(struct poly));
            newNode->coeff=ptr1->coeff*ptr2->coeff;
            newNode->exp=ptr1->exp+ptr2->exp;
            newNode->next=NULL;
            if(temp==NULL)
            {
                temp=newNode;
                ptr=temp;
            }
            else
            {
                ptr->next=newNode;
                ptr=newNode;
            }
            ptr2=ptr2->next;
        }
        start3=addPoly(start3,temp);
        ptr1=ptr1->next;
    }
    return start3;
}
int main()
{
    struct poly *start1=NULL;
    struct poly *start2=NULL;
    printf("Enter first poly:\n\n");
    start1=createPoly(start1);
    printf("\nprinting poly: ");
    printPoly(start1);
    printf("\n\nEnter second poly:\n\n");
    start2=createPoly(start2);
    printf("printing poly: ");
    printPoly(start2);
    struct poly* start3=multiply(start1,start2);
    printf("\nprinting multiplication poly: ");
    printPoly(start3);
}
