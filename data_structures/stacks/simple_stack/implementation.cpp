// This file contains the implementation of a simple stack
// By: Nick from CoffeeBeforeArch

#include "interface.h"

using namespace std;

// Add a new item to the stack
void Stack::push(int d){
    // Check if the stack is full
    // If full, exit with failure
    // Otherwise push new item
    if(is_full()){
        cout << "Error: Stack Overflow" << endl;
        exit(EXIT_FAILURE);
    }else{
        // Increment top of stack then store value at new position
        array[++top_of_stack] = d;
    }

    cout << "Push on to stack" << endl;
    print_stack();
}

// Remove an item from the stack
void Stack::pop(){
    // Check if stack is empty
    // If empty, exit with failure
    // Otherwise pop off top of stack
    if(is_empty()){
        cout << "Error: Stack Underflow" << endl;
        exit(EXIT_FAILURE);
    }else{
        // Clear element at top of stack then decrement top_of_stack
        array[top_of_stack--] = 0;
    }

    cout << "Pop off top of stack" << endl;
    print_stack();
}

// Look at top of stack
int Stack::peek(){
    // Check if stack is empty
    // If empty, exit with failure
    // Otherwise return top of stack value
    if(!is_empty()){
        cout << "Error: Stack Empty!";
        exit(EXIT_FAILURE);
    }else{
        return array[top_of_stack];
    }
}

// Clear the stack
void Stack::clear(){
    cout << "Dumping stack contents" << endl; 
    while(!is_empty()){
        pop();
    }
}

// Print the stack contents
void Stack::print_stack(){
    cout << "Stack contents" << endl;
    cout << "|\t\t|" << endl;
    cout << "|---------------|" << endl;
    for(int i = top_of_stack; i >= 0; i--){
        cout << "|\t" << array[i] << "\t|" << endl;
        cout << "|---------------|" << endl;
    }
}

// Check if stack is full
bool Stack::is_full(){
    // Last stack element should be at max size - 1
    return top_of_stack == size - 1;
}

// Check if stack is empty
bool Stack::is_empty(){
    // Empty stack is at index -1
   return top_of_stack == -1;
}
