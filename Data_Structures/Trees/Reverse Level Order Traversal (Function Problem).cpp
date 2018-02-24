/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void reversePrint(Node *root)
{
    queue< Node* > q;
    stack< int > s;
    if(!root)
    return;
    q.push(root);

    while(!q.empty()) {
        s.push(q.front()->data);
        if(q.front()->right) q.push(q.front()->right);
        if(q.front()->left) q.push(q.front()->left);
        q.pop();
    }
    while(!s.empty()) {
        cout << s.top() <<" ";
        s.pop();
    }
}