/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void make_diagnal_map( map< int , vector<int> > &pdiagonal , int d, Node *root ) {
	
	pdiagonal[d].push_back(root->data);
	// ifroot->left exist then push that in the map at next level (depth+1)
	if(root->left) make_diagnal_map( pdiagonal , d+1 , root->left );
	// now, since the left child has been completed (given priority in printing ) on the next level
	//insert the right child in the current depth
	if(root->right) make_diagnal_map( pdiagonal , d , root->right );
}

void diagonalPrint(Node *root)
{
   map< int , vector<int> > pdiagonal;
   
   if(root)
   make_diagnal_map(pdiagonal , 0 , root);
   
   for( auto it = pdiagonal.begin() ; it != pdiagonal.end() ; it++ ) {
   	for( auto itr = it->second.begin() ; itr != it->second.end(); itr++) {
   		cout << *itr << " ";
   	}
   }
}