/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* CreateNode(int data)
{
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->next=NULL;
    return n;
}

void InsertAtBeg(int data,Node** head)
{
	Node* n=CreateNode(data);
	n->next=*head;
	*head=n;
}

Node* Reverse(Node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* n=CreateNode(head->data);
	head=head->next;
	while(head!=NULL)
	{
		InsertAtBeg(head->data,&n);
		head=head->next;
	}
	return n;
}

