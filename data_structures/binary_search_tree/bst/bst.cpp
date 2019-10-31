// This program implements a binary tree in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <vector>
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
    
    // Search for a node with data "d"
    node *search(int d);
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

node *BinarySearchTree::search(int d){
    // Temp. node to use for traversal (init. to root)
    node *temp = root;

    // Keep traversing the tree until the node if found (or not)
    while(temp != nullptr){
        // Return the node we are looking for
        if(d == temp->data){
            cout << "X" << endl;
            return temp;
        // Go down the left path
        }else if(d < temp->data){
            cout << "L";
            temp = temp->left;
        // Go down the right path
        }else{
            cout << "R";
            temp = temp->right;
        }
    }
    // We didn't find the node...
    return nullptr;
}

int main(){
    // Create a new binary search tree
    BinarySearchTree bst;

    // Set the seed
    srand(1);

    // Insert 10 random nodes
    int data;
    vector<int> data_vec;
    for(int i = 0; i < 10; i++){
        // Random number between 0-999
        data = rand() % 1000;

        // Save the number so we can search for it later
        data_vec.push_back(data);
        cout << "Inserting node with data " << data << endl;

        // Insert the node (save the root if it's the first insert)
        bst.root = bst.insert_node(bst.root, data);
    }
    cout << endl;

    // Search for each of the inserted nodes
    for(int i : data_vec){
        cout << "Serching for node with data " << i << endl;
        bst.search(i);
    }

    return 0;
}
