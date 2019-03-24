// This program implements a basic singly linked list in C++
// By: Nick from CoffeeBeforeArch

#include "interface.h"

using namespace std;

int main(){
    // Create a new linked list
    LinkedList ll;

    // Insert a few nodes, alternating at head and tail
    for(int i = 0; i < 5; i++){
        // Insert at tail on even numbers
        ll.add_node(i * i);
    }

    for(int i = 0; i < 5; i++){
        ll.delete_node();
    }

    return 0;
}
