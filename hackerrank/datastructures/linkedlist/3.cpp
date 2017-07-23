/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node* l = (struct Node *)malloc(sizeof(Node));
    if(head==NULL)
    {   
        l->next=NULL;
        l->data=data;
        return l;
    }
    l->next=head;
    l->data=data;
    return l;
}
