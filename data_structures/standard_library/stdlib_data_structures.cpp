// This program shows off some elementary data structures included in
// the C++ standard library
// By: Nick from CoffeeBeforeArch

#include <iostream>

// Implementation of a singly linked list
#include <forward_list>

// Unsurprisingly, and implementation of a stack
#include <stack>

using namespace std;

void print_line(){
    for(int i = 0; i < 72; i++){
        cout << "-";
    }
    cout << endl;
}

// Simple function for printing the contents of a list
// Takes a forward list of integer type as an argument
void print_list(forward_list<int> int_sll){
    cout << "Printing List" << endl;
    print_line();

    // Iterator we'll use to access the list elements
    forward_list<int>::iterator it;

    // Iterate until we get to the end of the list
    for(it = int_sll.begin(); it != int_sll.end(); it++){
        // De-reference the list item
        cout << *it << "\t";
    }
    cout << endl;

    print_line();
}

void print_stack(stack<int> int_stack){
    cout << "Dumping Stack of size" << int_stack.size() << endl;
    print_line();

    cout << "TOP OF STACK" << endl;
    while(!int_stack.empty()){
        // Print top of stack
        cout << int_stack.top();
        // Pop off top of stack
        int_stack.pop();
        cout << endl;
    }
    cout << "BOTTOM OF STACK" << endl;
}

int main(){
    // Number of elments to add
    int N = 5;

    // Create a singly linked list
    forward_list<int> int_sll;

    // Create an iterator for the list (just before the beginning)
    // Iterators are just pointers to parts of STL containers
    forward_list<int>::iterator it = int_sll.before_begin();

    // Insert after the previous iterator's position
    // Will also allocate space for a new item
    it = int_sll.insert_after(it, 0);
    print_list(int_sll);

    for(int i = 1; i < N + 1; i++){
        if(i % 2){
            // Adds a new item into the beginning of the list
            int_sll.push_front(i);
        }else{
            // Insert an item at the end of the list
            it = int_sll.insert_after(it, i);
        }

        // Dump list contents
        print_list(int_sll);
    }

    // Create a stack
    stack<int> int_stack;

    // Push items on to the stack
    for(int i = 0; i < N; i++){
        int_stack.push(i*i);
    }

    // Dump the stack contents
    print_stack(int_stack);

    return 0;
}
