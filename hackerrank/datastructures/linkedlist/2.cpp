/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
  Node* l = (struct Node *)malloc(sizeof(Node));
  Node* p = (struct Node *)malloc(sizeof(Node));  
  p=head;

  if(p==NULL)
  { 
      l->data=data;
      l->next=NULL;
      return l;
  }
  while(head->next!=NULL){
      head = head->next;
  }  
  head->next=l;
  l->data=data;
  l->next=NULL;  
  return p;  
}
