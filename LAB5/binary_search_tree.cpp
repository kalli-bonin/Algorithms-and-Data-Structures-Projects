// Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <iostream>
#include "binary_search_tree.hpp"

using namespace std;

// Sets the left and right children to NULL, and initializes val.
BinarySearchTree::Node::Node( int new_val ) {
    val   = new_val;
    left  = NULL;
    right = NULL;
}

// Default constructor to initialize the tree and set root_ to NULL.
BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
    size_ = 0;
}

// Helper Function. Empties node in order to delete in deconstructor
BinarySearchTree::Node* empty(BinarySearchTree::Node* n) {
    if(n == NULL)
        return NULL;

    empty(n->left);
    empty(n->right);
    delete n;
    return NULL;
}

// Destructor of the class BinarySearchTree.
// It deallocates the memory space allocated for the binary search tree.
BinarySearchTree::~BinarySearchTree() {
    empty(getRootNode());
}

// Optional helper function that recursively gets the maximum depth for a given node.
int BinarySearchTree::getNodeDepth( Node* n ) const {// returns -1 for an empty tree
    if (n == NULL)
        return -1;
    else {
        int ldepth = getNodeDepth(n->left);
        int rdepth = getNodeDepth(n->right);

        if(ldepth <= rdepth)
            return rdepth+1;

        else
            return ldepth+1;
    }
}

//  Returns the number of nodes in the tree.
unsigned int BinarySearchTree::size() const {
	return size_;
}

// Returns the maximum value of a node in the tree.
// You can assume that this function will never be called on an empty tree.
int BinarySearchTree::max() const {
    Node* cur = root_;

    // loop to find the rightmost leaf
    while (cur->right != NULL) {
        cur = cur->right;
    }
    return(cur->val);}

// Returns the minimum value of a node in the tree.
// You can assume that this function will never be called on an empty tree.
int BinarySearchTree::min() const {
    Node* cur = root_;

    // loop to find the leftmost leaf
    while (cur->left != NULL) {
        cur = cur->left;
    }
    return(cur->val);
}

// Returns the maximum depth of the tree.
// A tree with only the root node has a depth of 0.
// You can assume that this function will never be called on an empty tree.
unsigned int BinarySearchTree::depth() const {
    return getNodeDepth(root_);
}

void inorder(BinarySearchTree::Node* n) {
    if(n == NULL)
        return;
    inorder(n->left);
    cout << n->val << " ";
    inorder(n->right);
}

// You can print the tree in whatever order you prefer. However, methods such
// as in-order or level-order traversal could be the most useful for debugging.
void BinarySearchTree::print() const {
    inorder(root_);
}

// Returns true if a node with the value val exists in the tree;
// otherwise, it returns false.
bool BinarySearchTree::exists( int val ) const {
    Node* cur = root_;

    while (cur != NULL) {
        if (cur->val == val)
            return true;
        else if (val > cur->val)
            cur = cur->right;
        else
            cur = cur->left;

    }
    return false;
}

// Helper function. Returns a pointer to the root node.
BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    return root_;
}

// Helper function. Returns the root node pointer address.
BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    return &root_;
}

// Inserts the value val into the tree.
// Returns false if val already exists in the tree, and true otherwise.
bool BinarySearchTree::insert( int val ) {
    Node** cur = getRootNodeAddress();

    if (exists(val)) //if value already exists, return false
        return false;

    while (*cur){
        if (val < (*cur)-> val)
            cur = &(*cur)->left;
        else
            cur = &(*cur)->right;
    }

    *cur = new Node(val);
    size_++;
    return true;
}

// Returns the minimum value of a node in the tree.
BinarySearchTree::Node* minValueNode(BinarySearchTree::Node* n) {
    if(n == NULL)
        return NULL;
    else if(n->left == NULL)
        return n;
    else
        return minValueNode(n->left);
}

// Removes the node with the value val from the tree.
// Returns true if successful, and false otherwise.
bool BinarySearchTree::remove( int val ) {
    // Creates a pointer to the address of the root node (which is a pointer)
    Node** cur = &root_;

    // While the current node (pointer) exists and its value is not equal to val
    while (*cur && (*cur)->val != val) {
        // If the current node value is less than val
        if ((*cur)->val < val) cur = &(*cur)->right; // Set cur to point to the address of the current node's right node
        else cur = &(*cur)->left; // Otherwise set cur to point to the address of the current node's left node
    }

    if (*cur == NULL) return false;

    Node* left = (*cur)->left;
    Node* right = (*cur)->right;

    // If left is NULL or right is NULL
    if (left == NULL || right == NULL) {
        delete *cur; // Free up memory held by the current node
        if (left) *cur = left; // If the left of the current node exists, set the current node to be 'left'
        else if (right) *cur = right; // Otherwise set the current node to be 'right'
        else *cur = NULL; // Otherwise set it to be NULL
    }

    // Else if both left is NULL or right is NULL
    else if (left != NULL && right != NULL) {
        Node **minNode = &((*cur)->right); // Create a pointer to the address of the current node's right node

        // Finds the right subtrees minimum node be setting minNode to minNode's left node until there are no more left nodes (NULL)
        while ((*minNode)->left) {
            minNode = &((*minNode)->left);
        }

        // Replaces the val of the current node with the value of minNode
        (*cur)->val = (*minNode)->val;

        // Replaces minNode with its right node, and then deletes the original minNode
        Node *temp = *minNode;
        *minNode = (*minNode)->right;
        delete temp;
    }

    size_--;
    return true;
}
