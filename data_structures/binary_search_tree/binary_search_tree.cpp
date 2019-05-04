// This program implements a binary tree in C++
//
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

struct node{
    // Pointers to left and right nodes
    node *left;
    node *right;

    // Data
    int data;

    // Constructor
    node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    // Root node of the tree
    node *root;

    // Simple constructor sets the root to NULL
    BinarySearchTree(){
        root = nullptr;
    }

    // Simple method for inserting a node
    node *insert_node(node* n, int d);
};

// Recursively traverse the tree until the node is nullptr
// (insertion point)
node *BinarySearchTree::insert_node(node *n, int d){
    // Case that we are inserting the node here
    if(n == nullptr){
        cout << "X" << endl;
        return new node(d);
    // Case the node is traversing down the left child's path
    }else if(d < n->data){
        cout << "L";
        n->left = insert_node(n->left, d);
    // Case we are traversing down the right child's path
    }else if(d > n->data){
        cout << "R";
        n->right = insert_node(n->right, d);
    // Case that we have duplicate entries (illegal)
    }else{
        assert(false);
    }
    
    // If this node was not nullptr, return it unchanged
    return n;
}

int main(){
    // Create a new binary search tree
    BinarySearchTree bst;

    // Set the seed
    srand(1);

    // Insert 10 random nodes
    int data;
    for(int i = 0; i < 10; i++){
        data = rand() % 1000;
        cout << "Inserting node with data " << data << endl;
        bst.root = bst.insert_node(bst.root, data);
    }
    return 0;
}
