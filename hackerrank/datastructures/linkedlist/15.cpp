/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    if(head==NULL)
    {
        return head;
    }
    Node* current = (struct Node *)malloc(sizeof(Node));
    Node* temp = (struct Node *)malloc(sizeof(Node));
    Node* prev = (struct Node *)malloc(sizeof(Node));
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=prev;
        current->prev=temp;
        prev=current;
        current=temp;
    }
    head=prev;
    return head;
}
