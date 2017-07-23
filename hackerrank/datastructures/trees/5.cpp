/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
void left(node* root)
{
    if(root==NULL)
    {
        return;
    }
    //cout << "#";
    
    left(root->left);
    cout << root->data << " ";
}
int ct=0;
void topView(node * root) {
    if(root==NULL)
    {
        return;
    }
    if(ct==0)
    {
        left(root->left);
        ct=1;
    }
    cout << root->data << " ";
    topView(root->right);
}

