#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    int checked;
    struct node* next;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;
void push(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    //printf("%d\n",n);
    temp->num=n;
    temp->next=NULL;
    temp->checked=0;
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
    int n,m,i,unchecked,skips;
    scanf("%d %d",&n,&m);
    unchecked=n;
    for(i=1;i<=n;i++)
    {
        push(i);
    }


    temp=head;
    while(temp!=NULL)
    {
        printf("%d ", temp->num);
        temp=temp->next;

    }
    printf("\n");
    tail->next=head;
    temp=head;
    while(unchecked>0)
    {
        if(unchecked==1)
            printf("Answer is %d\n", temp->num);

        temp->checked=1;
        unchecked--;
        skips=m;
        while(unchecked>0 && skips!=0)
        {
            temp=temp->next;
            if(temp->checked==0)
                skips--;
        }
    }
}
