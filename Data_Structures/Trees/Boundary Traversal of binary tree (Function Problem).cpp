/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printBoundary(Node *root)
{
    if(!root) return;
    
     Node* temp ;
     
     // print root
     cout << root->data << " " ;
     
     // print left boundary
     temp = root->left;
     if(temp)
     while(temp->left || temp->right) {
        cout << temp->data <<" ";
        if(temp->left)
            temp = temp->left;
        else if(temp->right)
            temp = temp->right;
     }
     
     // print leaf nodes
     stack <Node*> s;
     if(root->right) s.push(root->right);
     if(root->left) s.push(root->left);
     while(!s.empty()) {
         temp = s.top();
         s.pop();
         if(temp->right) s.push(temp->right);
         if(temp->left) s.push(temp->left); 
         if(temp->right == NULL && temp->left == NULL )
            cout << temp->data << " ";
     }
     
     // print right boundary
     
     temp = root->right;
     if(temp) {
         while(temp->right || temp->left) {
             s.push(temp);
             if(temp->right) temp = temp->right;
             else if(temp->left) temp = temp->left;
         }
     }
     while(!s.empty()) {
         cout<< s.top()->data << " ";
         s.pop();
     }
     
}