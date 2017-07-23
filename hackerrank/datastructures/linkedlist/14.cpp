/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
    Node* l = (struct Node *)malloc(sizeof(Node));
    Node* p = (struct Node *)malloc(sizeof(Node));
    Node* pre = (struct Node *)malloc(sizeof(Node));
    if(head==NULL)
    {
        l->data=data;
        return l;
    }
    else if((head->data)<=data)
    {
        p=head;
        pre=NULL;
        while(p!=NULL&&((p->data)<data))
        {
            pre=p;
            p=p->next;
        }
        if(p==NULL)
        {
            l->data=data;
            pre->next=l;
            l->prev=pre;
            l->next=NULL;
            return head;
        }
        l->data=data;
        pre->next=l;
        l->prev=pre;
        l->next=p;
        p->prev=l;
        return head;
    }
    l->data=data;
    l->next=head;
    head->prev=l;
    return l;   
}
