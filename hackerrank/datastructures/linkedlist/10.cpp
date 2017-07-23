/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
     Node* l = (struct Node *)malloc(sizeof(Node));
     l=head;
     int ct=0;
     while(l!=NULL)
     {
         ct++;
         l=l->next;
     }
     int ans=ct-(positionFromTail+1);
    while(ans!=0)
    {
        head=head->next;
        ans--;
    }
    return head->data;
}

