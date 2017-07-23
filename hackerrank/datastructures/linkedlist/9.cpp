/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(headA==NULL)
    {
        return headB;
    }
    else if(headB==NULL)
    {
        return headA;
    }
    Node* p = (struct Node *)malloc(sizeof(Node));
    Node* l = (struct Node *)malloc(sizeof(Node));
    if((headA->data)<(headB->data))
    {   
        l=headA;
        p=headA;
        headA=headA->next;
    }
    else
    {   
        l=headB;
        p=headB;
        headB=headB->next;
    }
    while(headA!=NULL && headB!=NULL)
    {
        if((headA->data)<(headB->data))
        {
            p->next=headA;
            p=p->next;
            headA=headA->next;
        }
        else
        {
            p->next=headB;
            p=p->next;
            headB=headB->next;
        }
    }
    if(headA==NULL)
    {
        p->next = headB;
    }
    else
    {
        p->next=headA;
    }   
    
    /*if(headA->next==NULL)
    {
        if((headA->data)<(headB->data))
        {
            headA->next=headB;
            p->next=headA;
        }
        else
        {
            while(headB->next!=NULL && ((headA->data)>(headB->data)))
            {
                p->next=headB;
                p=p->next;
                headB=headB->next;
            }
            if(headB->next==NULL)
            {   
                if((headA->data)<(headB->data))
                {
                    p->next=headA;
                    p=p->next;
                    p->next=headB;
                }
                else
                {
                    p->next=headB;
                    p=p->next;
                    p->next=headA;
                }
            }
            else
            {
                p->next=headA;
                p=p->next;
                p->next=headB;
            }
        }
    }
    else if(headB->next==NULL)
    {
        if((headB->data)<(headA->data))
        {
            headA->next=headA;
            p->next=headB;
        }
        else
        {
            while(headA->next!=NULL && ((headB->data)>(headA->data)))
            {
                p->next=headA;
                p=p->next;
                headA=headA->next;
            }
            if(headA==NULL)
            {
                if((headB->data)<(headA->data))
                {
                    p->next=headB;
                    p=p->next;
                    p->next=headA;
                }
                else
                {
                    p->next=headA;
                    p=p->next;
                    p->next=headB;
                }                
            }
            else
            {
                p->next=headB;
                p=p->next;
                p->next=headA;
            }
        }        
    }*/
    return l;
}

