// C++ program for an efficient solution to check if
// a given array can represent Preorder traversal of
// a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;
 
bool preOrderCanRepresentBST(int pre[] , int n) {
	// create an empty stack
	stack <int> stk;

	//create a variable root and initialise it to minimum integer
	int root = INT_MIN;
	for(int i = 0; i < n; i++) {

		// if pre[i] is not in right sub tree of root
		if(pre[i] < root)
			return false;

		// if pre[i] is in right subtree of stk.top() 
		// and stk is not empty  
		while(!stk.empty() && pre[i] > stk.top()) {

			// stk.top() becomes root
			root = stk.top();
			// pop the top of stk as the left-subtree of current root is verified
			stk.pop();
		}
		// stack is empty or pre[i] < stk.top()
		stk.push(pre[i]);
	}
	return true;
}
 
// Driver program
int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    cout << preOrderCanRepresentBST(pre1, n);
 
    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    cout << preOrderCanRepresentBST(pre2, n);
 
    return 0;
}