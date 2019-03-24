// This file contains the interface for the singly linked list node
// and list objects

#include <iostream>
#include <cstddef>
#include <assert.h>

// Simple node of the list
// Contains data, and a pointer to the next node
struct Node {
    int data;
    Node *next;

    // Constructor
    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList {
private:
    // Pointer to list head
    Node *head;
public:
    // Constructor initialzing NULL pointers
    LinkedList(){
        head = NULL;
    }

    // Append new node to the end of the list
    void add_node(int d);

    // Remove node at the end of the list
    void delete_node();

    // Print out the list
    void print_list();
};

