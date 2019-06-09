// This program implements merge sort in C++
// By: From CoffeeBeforeArch

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// Initialize a vector with random numbers
void init_vector(vector<int> &vec, unsigned n){
    for(unsigned i = 0; i < n; i++){
        vec.push_back(rand() % 100);
    }
}

// Helper function for printing a vector
void print_vector(vector<int> vec){
    for(unsigned i = 0; i < vec.size(); i++){
        cout << vec[i] << "\t";
    }
    cout << endl;
}

// Helper function to print out sub-list within original vector
void print_range(vector<int> vec, unsigned start, unsigned end){
    for(unsigned i = start; i < end + 1; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Helper function to print intermediate results
void print_sub_vectors(vector<int> v1, vector<int> v2){
    for(unsigned i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << "\t";

    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
}

int main(){
    // Vector that we will sort
    vector<int> vec;
    
    // Initialize a vector with "n" elements
    unsigned n = 8;
    init_vector(vec, n);
    
    // Print the vectors before sorting
    cout << "ORIGINAL VECTOR" << endl;
    print_vector(vec);
    
    merge_sort(vec, 0, vec.size() - 1);

    // Print out the result
    cout << "FINAL VECTOR" << endl;
    print_vector(vec);

    return 0;
}
