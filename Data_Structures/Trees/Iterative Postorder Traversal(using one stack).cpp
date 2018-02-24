void iterative_post_order_traversal(node* root) 
{
	node *current , *temp;
	stack< node* > st;
	if(!root ){ 
		return;
	}
	do {
		while(root) {
			if(root->right) st.push(root->right);
			st.push(root);
			root = root->left;
		}

		root = st.top();
		st.pop();
		if(root->right && root->right == st.top()) {
			temp = st.top();
			st.pop();
			st.push(root);
			root = temp;
		}
		else {
			cout << root->data << " ";
			root = NULL;
		}

	}while(!st.empty())
}