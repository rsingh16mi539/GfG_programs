// Iterative pre order traversal
void iterativePreorder(node *root)
{
    
    if (root == NULL)
       return;
 
    stack<node *> Stk;
    Stk.push(root);
 

    while (Stk.empty() == false)
    {
        struct node *node = Stk.top();
        printf ("%d ", node->data);
        Stk.pop();
 
        if (node->right)
            Stk.push(node->right);
        if (node->left)
            Stk.push(node->left);
    }
}