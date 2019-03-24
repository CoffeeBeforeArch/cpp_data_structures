// This file implements the methods of the 'LinkedList' class
// By: Nick from CoffeeBeforeArch

#include "interface.h"

using namespace std;

// Append node to the end of the list
void LinkedList::add_node(int d){
    // Create new node with value 'd'
    Node *new_node = new Node(d);
    
    // Create temp for walking the list
    Node *temp = head;

    // Handle case of empty list
    // Otherwise perform normal insertion
    if(temp == NULL){
        head = new_node;
    } else{
        // Walk the list until the next node is NULL
        while(temp->next != NULL){
            temp = temp->next;
        }
        // Assign previous tail's 'next' to be our new node
        temp->next = new_node;
    }
    
    cout << "Add node with data: " << d << endl;
    print_list();
}

// Delete node at tail of list
void LinkedList::delete_node(){
    // Check if list is empty
    assert(head != NULL);

    // Walk the list and save the previous and current Node
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    // Handle case where there is only 1 list item
    // Otherwise normal tail delete
    if(prev == NULL){
        head = NULL;
    }else{
        prev->next = temp->next;
    }
    delete temp;

    cout << "Delete node" << endl;
    print_list();
}

// Prints out the list
void LinkedList::print_list(){
    for(int i = 0; i < 72; i++){
        cout << '-';
    }
    cout << endl;
    
    Node *temp = head;
    cout << "List\t";
    while(temp != NULL){
        cout << temp->data << '\t';
        temp = temp->next;
    }
    cout << endl;

    for(int i = 0; i < 72; i++){
        cout << '-';
    }
    cout << endl;
}
