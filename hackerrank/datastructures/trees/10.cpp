/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
   bool left(Node* root, int data)
   {
       if(root==NULL)
       {
           return true;
       }
       if(root->data >= data)
       {
           return false;
       }
       return left(root->left, root->data) && right(root->right, root->data) && left(root->right,data);
   }

   bool right(Node* root, int data)
   {
       if(root==NULL)
       {
           return true;
       }
       if(root->data <= data)
       {
           return false;
       }
       return left(root->left,root->data) && right(root->right, root->data) && right(root->left,data);
   }

   bool checkBST(Node* root) {
       if(root == NULL)
       {
           return true;
       }
       return left(root->left, root->data) && right(root->right,root->data);
   }

