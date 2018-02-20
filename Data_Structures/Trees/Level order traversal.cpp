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
//You are required to complete this method
queue < Node * > q;
void levelOrder(Node* node)
{
   if(node != NULL)
    q.push(node);
   while(!q.empty()) {
       if(q.front()) {
          cout<<q.front()->data<<" ";
          q.push( q.front()->left );
          q.push( q.front()->right );
        }
        q.pop();
   }
}
