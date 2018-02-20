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
void levelOrder(Node* node)
{
    queue<Node*> q;
    int size , temp;
    if(node != NULL ) {
    	q.push(node);
    	size = 1;
    }
    while(!q.empty()) {
    	temp = 0;
    	while(size--) {
    		if(q.front()->left){ q.push(q.front()->left); temp++; }
    		if(q.front()->right){ q.push(q.front()->right); temp++; }
    		cout<<q.front()->data<<" ";
    		q.pop();
    	}
    	cout<<"$ ";
    	size = temp;
    }
}
