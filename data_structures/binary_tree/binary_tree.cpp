// This program implements a binary tree in C++
//
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <math.h>

using namespace std;

struct node{
    // Pointers to left and right nodes
    node *parent;
    node *left;
    node *right;

    // Data
    int data;

    // Constructor
    node(int d){
        data = d;
        parent = nullptr;
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
void BinaryTree::insert_node(node *node, int d){

}

int main(){
    
    return 0;
}
