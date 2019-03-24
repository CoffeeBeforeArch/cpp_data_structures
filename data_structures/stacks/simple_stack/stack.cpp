// This program implements a simple stack in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>

#include "interface.h"

using namespace std;

int main(){
    // Create a new stack
    Stack simple_stack;

    // Add some elements to the stack
    for(int i = 0; i < 5; i++){
        simple_stack.push(i);
    }

    // Remove some elements from the stack
    for(int i = 0; i < 2; i++){
        simple_stack.pop();
    }

    // Clear the rest of the entries
    simple_stack.clear();

    return 0;
}
