/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* l1 = (struct Node *)malloc(sizeof(Node));
    Node* l2 = (struct Node *)malloc(sizeof(Node));
    if(head==NULL || head->next==NULL)
    {
        return false;
    }
    l1=head;
    l2=head;
    while(l1!=NULL && l2!=NULL && l2->next!=NULL)
    {
            l1=l1->next;
            l2=l2->next;
            l2=l2->next;
        
        if(l1==l2)
        {
            return true;
        }
    }
    return false;
}
