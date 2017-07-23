/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    Node* l = (struct Node *)malloc(sizeof(Node));
    Node* pre = (struct Node *)malloc(sizeof(Node));
    l=head->next;
    pre=head;
    if(head==NULL)
    {
        return head;
    }
    while(l!=NULL)
    {
        if((l->data)==(pre->data))
        {
            pre->next=l->next;
            l=l->next;
        }
        else
        {
            pre=pre->next;
            l=l->next;
        }
    }
    return head;
}
