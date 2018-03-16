void reverse()
{
    struct node *prev=NULL, *current= head, *nextnode= head->next;
    while(current!=NULL)
    {
        current->next=prev;
        prev=current;
        current=nextnode;
        if(nextnode!=NULL)
            nextnode=nextnode->next;
    }
    head=prev;
}

void rec_rev_genuine(struct node *prev, struct node *current)
{
    if(current==NULL)
        {   head=prev;
            return;
        }
    rec_rev_genuine(current,current->next);
    current->next=prev;
    return;
}
