// C++ program to print inorder traversal of a Binary Search
// Tree (BST) without recursion and stack
#include <bits/stdc++.h>
using namespace std;
 
// BST Node
struct Node
{
    Node *left, *right, *parent;
    int key;
};
 
// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->parent = temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with
   given key in BST */
Node *insert(Node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
    {
        node->left  = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// Function to print inorder traversal using parent
// pointer
void inorder(Node *root) {
    // we have not traversed left subtree yet
    bool leftdone = false;
    // while the root is not NULL
    while(root) {
        // if left sub-tree is not traversed
        if(!leftdone) {
            //then got to the left subtree of root
            while(root->left) root = root->left;
            // mark that left subtree is done
            leftdone = true;
        }
    // print the current node
        cout << root->key << " ";
    
    // if the current node has a right child go to its right sub-tree
    // by making right node of root a s root
        if(root->right) {
            root = root->right;
            leftdone = false;
        }
        //if current root node has a parent
        else if(root->parent) {
            
            // and the current root is right child of its parent
            // trace back to its parent as right-subtree is completed
            while(root->parent && root == root->parent->right) {
                root = root->parent;
            }
            // now if a left sub tree is completed go to its parent node
            if(root->parent) {
                root = root->parent;
            }
            // or if complete tree is done terminate the loop
            else 
                break;
        }

    }
}

int main(void)
{
    Node * root = NULL;
 
    root = insert(root, 24);
    root = insert(root, 27);
    root = insert(root, 29);
    root = insert(root, 34);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 22);
    root = insert(root, 13);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 6);
 
    printf("Inorder traversal is \n");
    inorder(root);
 
    return 0;
}