#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node* next;
};
struct node *head = NULL, *tail= NULL, *temp, *curr, *next, *prev;
void insert(int x)
{
    temp=(struct node *)malloc(sizeof(struct node));
    if(head==NULL && tail==NULL)
    {
        temp->next=NULL;
        temp->n=x;
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=NULL;
        temp->n=x;
        tail->next=temp;
        tail=temp;
    }
}
void pairwise()
{
    curr=head;
    if(curr==NULL)
        return;
    next=head->next;
    if(next==NULL)
        return;
    prev=NULL;

    curr->next=next->next;
    next->next=curr;
    prev=curr;
    head=next;
    curr=curr->next;
    if(curr==NULL)
        {   head=next;
            return;
        }
    next=curr->next;

    while(curr!=NULL && next!=NULL)
    {
        curr->next=next->next;
        next->next=curr;
        prev->next=next;
        prev=curr;
        curr=curr->next;
        if(curr==NULL)
            break;
        else
            next=curr->next;
    }



}
void print()
{
    temp=head;
    while(temp!=NULL)
        {
            printf("%d ",temp->n);
            temp=temp->next;
        }
    printf("\n");
}
int main()
{
    insert(1);
    insert(5);
    insert(7);
    insert(8);
    insert(2);
    insert(3);
    print();
    pairwise();
    print();
}
