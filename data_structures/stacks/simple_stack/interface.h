// This file specifies the interface for a stack class
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <cstdlib>

class Stack {
private:
    int *array;
    int top_of_stack;
    int size;
public:
    // Give it a default size in case the user forgets
    Stack(int s=10){
        // Update the stack size
        size = s;
        // Allocate the stack
        array = new int[size];
        // Set the top of stack to invalid value
        top_of_stack = -1;
    }

    // Add a new item to the stack
    void push(int d);
    // Remove an item from the stack
    void pop();
    // Look at top of stack
    int peek();
    // Clear the stack
    void clear();
    // Print the stack contents
    void print_stack();
private:
    // Check if stack is full (avoid overflow)
    bool is_full();
    // Check if stack is empty (avoid underflow)
    bool is_empty();
};

