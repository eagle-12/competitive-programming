/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.
    Node* l = (struct Node *)malloc(sizeof(Node));
    l=headB;
    while(headA!=NULL)
    {
        while(headB!=NULL)
        {
            if(headB==headA)
            {
                return headA->data;
            }
            headB=headB->next;
        }
        headB=l;
        headA=headA->next;
    }
    return 0;
}
