/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    node* ptr = root;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
        if(ptr->data)
        {
            cout << ptr->data;
            ptr = root;
        }
    }
}

