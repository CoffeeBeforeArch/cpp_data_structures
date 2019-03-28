// This program implements Bubble Sort in C++
// By: Nick from CoffeeBeforeArch

#include <stdlib.h>

// Swaps to elements in memory
// Takes memory locations a and b as arguments
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Performs bubble sort
// Takes an array and its length as arguments
void bubble_sort(int *array, int n){
    // Skips trivial last iteration
    for(int i = 0; i < n - 1; i++){
        // Propagate largest remaining element to the top
        // Remove "i" sorted elements each iteration 
        for(int j = 0; j < n - i - 1; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(){
    // Allocate an array of size n
    int n = 7;
    int array[n];

    // Initialize array with random numbers
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100;
    }

    // Sort the array
    bubble_sort(array, n);

    return 0;
}
