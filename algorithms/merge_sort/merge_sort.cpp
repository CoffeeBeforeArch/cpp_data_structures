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

// Merges to sorted sub-lists
void merge(vector<int> &vec, unsigned start, unsigned middle, unsigned end){
    cout << "Call merge for Start = " << start << ", End = " << end << endl;
    // Not sorting in place. Use two temp vectors
    // Initialize left-hand elements
    unsigned elements_left = middle - start + 1;
    vector<int> tmp_left;
    for(unsigned i = 0; i < elements_left; i++){
        tmp_left.push_back(vec[start + i]);
    }
    
    // Initialize right-hand elements
    unsigned elements_right = end - middle;
    vector<int> tmp_right;
    for(unsigned i = 0; i < elements_right; i++){
        tmp_right.push_back(vec[middle + 1 + i]);
    }
    
    print_sub_vectors(tmp_left, tmp_right);

    // Compare vectors and add elements to the final result
    unsigned i = 0;
    unsigned j = 0;
    int pos = start;
    while((i < tmp_left.size()) && (j < tmp_right.size())){
        // Add left-hand element if it's smaller
        // Otherwise add right-hand element 
        if(tmp_left[i] <= tmp_right[j]){
            vec[pos] = tmp_left[i];
            i++;
        }else{
            vec[pos] = tmp_right[j];
            j++;
        }

        // Increment position in final vector
        pos++;
    }

    // Clean up remaining left-hand elements
    while(i < tmp_left.size()){
        vec[pos] = tmp_left[i];
        i++;
        pos++;
    }
    
    // Clean up remaining right-hand elements
    while(j < tmp_right.size()){
        vec[pos] = tmp_right[j];
        j++;
        pos++;
    }
    
    print_range(vec, start, end);
}

// Recursive function for sorting the array
void merge_sort(vector<int> &vec, unsigned l, unsigned r){
    cout << "Merge Sort for L = " << l << ", R = " << r << endl;
    // Merge until we are left with a single element
    if(l < r){
        // Calculate mid-point of vector
        int mid = (l + r) / 2;

        // Sort the sub-vectors
        merge_sort(vec, l, mid);
        merge_sort(vec, mid + 1, r);

        // Merge the two sub-lists 
        merge(vec, l, mid, r);
    }
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
