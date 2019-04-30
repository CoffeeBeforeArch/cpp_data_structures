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

node *insert_node(node *root, node *new_node){
    
}

int main(){
    // Create the root node
    node *root = new node(rand() % 100);
    
    return 0;
}
