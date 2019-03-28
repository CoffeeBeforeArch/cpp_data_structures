// This program implements selection sort in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Performs insertion sort on "array"
// Takes an array, and its length as arguments
void insertion_sort(int *array, int n){
    // Keep track the key and value of current minimum
    int min_key;
    // Skip trivial last iteration (only 1 element left to sort)
    for(int i = 0; i < n - 1; i++){
        // Set current index to be minimum
        min_key = i;

        // Loop over remaining elements
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min_key]){
                min_key = j;
            }
        }
        
        // Swap for the min element 
        swap(&array[i], &array[min_key]);
    }
}

int main(){
    // Create an array of size N
    int n = 7;
    int array[n];

    // Fill our array with random numbers
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100;
    }

    // Sort the array
    insertion_sort(array, n);

    return 0;
}
