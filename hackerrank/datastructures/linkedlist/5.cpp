/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
  Node* l = (struct Node *)malloc(sizeof(Node));
  Node* pre = (struct Node *)malloc(sizeof(Node));
  l=head;  
  if(position==0)
  {
      pre=head->next;
      free(head);
      return pre;
  }
  else
  {
      int ct=0;
      while(ct<position)
      {
          pre=head;
          head=head->next;
          ct++;
      }
      pre->next=head->next;
      free(head);
      return l;
  }
  return l;  
}

