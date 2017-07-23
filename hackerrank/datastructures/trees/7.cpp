/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value) {
    if(root == NULL)
    {
        node* head = (node*)malloc(sizeof(node*));
        head->left =NULL;
        head->right = NULL;
        head->data = value;
        return head;
    }
   node* head = root;
    node* pre = (node*)malloc(sizeof(node*));
    pre = NULL;
    int flag=0;
    while(head!=NULL)
    {
        if(head->data > value)
        {
            pre = head;
            head = head->left;
            flag=0;
        }
        else
        {
            pre = head;
            head = head->right;
            flag=1;
        }
    }
    if(flag==0)
    {
        struct node* h = (node*)malloc(sizeof(node));
        h->data = value;
        h->left = NULL;
        h->right = NULL;
        pre->left = h;
    }
    else
    {
        struct node* h = (node*)malloc(sizeof(node));
        h->data = value;
        h->left = NULL;
        h->right = NULL;
        pre->right = h;       
    }
   return root;
}

