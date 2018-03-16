#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node *prev;
    struct node *next;
};
struct node* head = NULL;
struct node* tail = NULL;
struct node* ptemp;
void print()
{
    ptemp=head;
    if(head==NULL && tail==NULL)
        printf("Empty\n");

    while(ptemp!=NULL)
        {
            printf("%d ",ptemp->n);
            ptemp=ptemp->next;
        }
    printf("\n");

}
void insertbeg(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(head==NULL && tail==NULL)
    {
       temp->next=NULL;
       temp->prev=NULL;
       temp->n=x;
       head=temp;
       tail=temp;
    }
    else
    {
        temp->next=head;
        temp->prev=NULL;
        temp->n=x;
        head->prev=temp;
        head=temp;
    }
}
void insertlast(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(head==NULL && tail==NULL)
    {
       temp->next=NULL;
       temp->prev=NULL;
       temp->n=x;
       head=temp;
       tail=temp;
    }
    else
    {
        temp->next=NULL;
        temp->prev=tail;
        tail->next=temp;
        temp->n=x;
        tail=temp;
    }
}
void removefirst()
{
    struct node *temp;
    if(head==NULL && tail==NULL)
        printf("List empty");

    else if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        temp=head->next;
        head=head->next;
        temp->prev=NULL;
    }

}
void removelast()
{
    struct node *temp;
    if(head==NULL && tail==NULL)
        printf("List empty");
    else if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        temp=tail->prev;
        tail=tail->prev;
        temp->next=NULL;
    }

}
void removeat(int x)
{
    struct node *temp, *prev1, *next1;
    if(head==NULL && tail==NULL)
        printf("List empty");
    else
    {
        temp=head;
        int i;
        for(i=1;i<x;i++)
        {
            if(temp==NULL)
                break;
            temp=temp->next;
        }
        if(temp==NULL)
            printf("Element doesn't exist");
        prev1=temp->prev;
        next1=temp->next;
        prev1->next=next1;
        next1->prev=prev1;
    }
}
int main()
{   int n,x;
    while(1)
    {
        printf("Enter the option from question\n");
        scanf("%d",&n);
        if(n==1)
            {   scanf("%d",&x);
                insertbeg(x);
            }
        else if(n==2)
            {   scanf("%d",&x);
                insertlast(x);
            }
        else if(n==3)
            {  scanf("%d",&x);
                removeat(x);
            }
        else if(n==4)
            removefirst();
        else if(n==5)
            removelast();
        else if(n==6)
            print();
        else
            exit(0);
    }
}
