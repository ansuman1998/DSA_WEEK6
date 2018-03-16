#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    int visited;
    struct node* next;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;
void push(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("%d\n",x);
    temp->x=x;
    temp->next=NULL;
    temp->visited=0;
    if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
    else
        {
            tail->next=temp;
            tail=temp;
        }

}
int main()
{
    int n,i;
    printf("Enter 0 to generate acyclic graph and 1 for cyclic graph ");
    scanf("%d",&n);
    int k=1000;
    while(k!=0)
    {
        push(rand());
        k--;
    }
    if(n==1)
        tail->next=head;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->visited==1)
        {
            printf("1\n");
            return;
        }
        temp->visited=1;
        temp=temp->next;

    }
    printf("0\n");
}
