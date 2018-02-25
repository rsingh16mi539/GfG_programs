// A function to check if leaf treaversal of two trees are same or not
// Expected space complexity is O(h1 + h2) 
bool check( node *root1 , node *root2) {
	// declare two empty stacks
	stack<node*> s1,s2;
	// declare two temporary nodes
	node *t1, *t2;
	// push root1 into stack1
	if(root1) s1.push(root1);
	// push root2 into stack2
	if(root2) s2.push(root2);

	// process even if only one state is none empty 
	while(!s1.empty() || !s2.empty()) {

		// if either of any states are empty which means one stack has more leaf nodes
		if(s1.empty() || s2.empty()) return false ;
		// set t1 as stack1 top
		t1 = s1.top();	s1.pop();
		//search for first leaf node in s1
		while(!s1.empty() && (t1->right || t1->left)) {
			if(t1->right) s1.push(t1->right);
			if(t1->left) s1.push(t1->left);
			t1 = s1.top();
			s1.pop();
		}
		// set t2 as stack2 top
		t2 = s2.top();	s2.pop();
		// search for first leaf node in s2
		while(!s2.empty() && (t2->right || t2->left)) {
			if(t2->right) s2.push(t2->right);
			if(t2->left) s2.push(t2->left);
			t2 = s2.top();
			s2.pop();
		}
		// if corresponding leaf nodes don't have same value return false
		if(t1->data != t2->data) return false;
	}
	return true;
}