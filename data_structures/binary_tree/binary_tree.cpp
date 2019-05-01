// This program implements a binary tree in C++
//
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <math.h>

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

class BinaryTree {
private:
    node *root;

public:
    // Simple constructor sets the root to NULL
    BinaryTree(){
        root = nullptr;
    }

    // Simple method for inserting a node
    void insert_node(node* n, int d);
};

// Inserts a node with data "d"
void BinaryTree::insert_node(node *n, int d){
    // Temp node for swapping
    node *temp = root;

    // Create a new node
    node *new_node = new node(d);

}

int main(){
    
    return 0;
}
