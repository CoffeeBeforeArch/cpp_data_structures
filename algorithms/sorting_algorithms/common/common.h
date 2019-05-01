// This file contains some utility functions to help explain sorting
// examples
// By: Nick from CoffeeBeforeArch

#include <iostream>

using namespace std;

// Prints out an array of length 'n'
// Takes an array and its length as arguments
void print_array(int *array, int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << '\t';
    }
    cout << endl;
    cout << endl;
}

// Prints a dividing line
void print_dividing_line(){
    for(int i = 0; i < 72; i++){
        cout << '-';
    }
    cout << endl;
}

// Prints two elements being swapped and the remaining vector
// on separate lines
// Takes an array, index of swapping elements, and array size
// as arguments
void print_swap(int *array, int a, int b, int n){
    print_dividing_line();

    for(int i = 0; i < n; i++){
        if((i == a) || (i == b)){
            cout << array[i];
        }
        cout << "\t";
    }
    cout << endl;
    cout << endl;

    for(int i = 0; i < n; i++){
        if((i != a) && (i != b)){
            cout << array[i];
        }
        cout << "\t";
    }
    cout << endl;
    cout << endl;
}


