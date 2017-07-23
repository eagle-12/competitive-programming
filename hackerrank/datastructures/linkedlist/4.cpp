/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
  Node* l = (struct Node *)malloc(sizeof(Node));
  Node* p = (struct Node *)malloc(sizeof(Node));
  Node* pre = (struct Node *)malloc(sizeof(Node));  
  p = head;  
  if(head==NULL)
  {
      l->data=data;
      l->next=NULL;
      return l;
  }
  else if(position==0)
  {
      l->data=data;
      l->next=head;
      return l;
  }
  int ct=0;  
  while(ct<position)
  {
      pre=head;
      head=head->next;
      ct++;
  }
  pre->next=l;
  l->next=head;
  l->data=data;
  return p;
}
