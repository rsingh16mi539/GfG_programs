void Morris_traversal_for_Preorder(tNode *root) {
	node *current;
	while(root) {
		if(root->left == NULL) {
			cout << root->data << " ";
			root = root->right;
		}
		else {
			current = root->left;
			while(current->right && current->right!=root) current = current->right;

			if(current->right == NULL) {
				current->right = root;
				cout << root->data << " ";
				root = root->left;
			}
			else {
				current->right = NULL;
				root = root->right;
			}
		}
	}
}