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

void print_vector(vector<int> &vec){
    for(unsigned i = 0; i < vec.size(); i++){
        cout << vec[i] << "\t";
    }
    cout << endl;
}

// Merges to sorted sub-lists
void merge(){

}

// Recursive function for sorting the array
void merge_sort(vector<int> &vec, unsigned l, unsigned r){
    // Merge until we are left with a single element
    if(l < r){
        // Calcualte mid-point of vector
        int mid = (l + r) / 2;

        // Sort the sub-vectors
        merge_sort(vec, l, mid);
        merge_sort(vec, mid + 1, r);
    }
    for(unsigned i = l; i < r; i++){
        cout << vec[i] << "\t";
    }
    cout << endl;
}

int main(){
    // Vector that we will sort
    vector<int> vec;
    
    // Initialize a vector with "n" elements
    unsigned n = 10;
    init_vector(vec, n);

    merge_sort(vec, 0, vec.size() - 1);

    // Print out the result
    print_vector(vec);

    return 0;
}
