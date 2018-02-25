/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should print vertical order such that each vertical line
   is separated by $ */

void make( map< int, vector<int> > &vt , int d, Node *root) {
    vt[d].push_back(root->data);
    if(root->left) make(vt, d-1, root->left);
    if(root->right) make(vt, d+1, root->right);
}

void verticalOrder(Node *root)
{
    map< int, vector<int> > vt;
    int d;
    if(root) make(vt, 22, root);
    
    for(auto it = vt.begin(); it != vt.end(); it++) {
        for(auto itr = it->second.begin() ; itr != it->second.end() ; itr++) {
            cout << (*itr) << " ";
        }
        cout<<"$";
    }
    
}