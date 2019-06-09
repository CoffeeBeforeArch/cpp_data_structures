// This file contains a collection of sorting algorithm implementations
// and performance data collection utilities
// By: Nick from CoffeeBeforeArch

// For use of rand()
#include <stdlib.h>

// Initializes an array "a" of size "N"
// Takes:
//  a:  Pointer to the array
//  N:  Length of the array
// Reurns:
//  NA
void init_array(int *a, int N){
    for(int i = 0; i < N; i++){
        a[i] = rand() % 100000;
    }
}

// Swaps two elments in memory
// Takes:
//  a:  First location
//  b:  Second location
// Returns:
//  NA
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort
// Takes:
//  a:  Array of unsorted elements
//  N:  Lenght of the array
// Returns:
//  NA
void bubble_sort(int *a, int N){
    // Bubble all larger elements to the top
    // Skips trivial last iteration of sorting a single element
    for(int i = 0; i < N - 1; i++){
        // Larger elements bubble to their correct position
        // Ignores sorted sub-array of size "i"
        for(int j = 0; j < N - 1 - i; j++){
            // Bubble up the larger element
            if(a[j] > a[j + 1]){
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// Insertion Sort
// Takes:
//  a:  Array of unsorted elements
//  N:  Length of the array
// Returns:
//  NA
void insertion_sort(int *a, int N){
    // Places each element into its position of a sorted sub-list
    // Skips trivial first iteration of sub-list size of 1
    int temp;
    for(int i = 1; i < N; i++){
        // Save the ith element because shifting overwrites it
        temp = a[i];

        // Shift over as many elements of the sub-list as necessary
        int j = i - 1;

        // Locate the insertion point ...
        while((j >= 0) && (a[j] > temp)){
            a[j + 1] = a[j];
            j = j - 1;
        }

        // ... and insert the value at that spot
        a[j + 1] = temp;
    }
}

// Selection Sort
// Takes:
//  a:  Array of unsorted elements
//  N:  Length of the array
// Return:
//  NA
void selection_sort(int *a, int N){
    // Keep track of the current min value's index
    int min_key;

    // Skips trivial last iteration of sorting a single element
    for(int i = 0; i < N - 1; i++){
        // Set current index to be minimum
        min_key = i;

        // Check remaining elements if the theyare smaller
        for(int j = i + 1; j < N; j++){
            // Replace the min_key if the new elements is smaller
            if(a[j] < a[min_key]){
                min_key = j;
            }
        }
       
        // Don't swap if the element was in its correct place
        if(i != min_key){
            swap(&a[i], &a[min_key]);
        }
    }
}

// Merge Sort (Two functions)
// Merge
// Takes:
//  a:      Array to merge sorted sub-array into
//  start:  Start point of sub-array in the main array
//  mid:    Mid-point of sub-array in the main array
//  end:    End-point of sub-array in the main array
// Returns:
//  NA
void merge(int *a, int start, int mid, int end){
    // Use temp arrays for sorting instead of doing it in place
    // Initialize left-hand elements
    int left_size = mid - start + 1;
    int *tmp_left = new int[left_size];
    for(int i = 0; i < left_size; i++){
        tmp_left[i] = a[start + i];
    }
    
    // Initialize right-hand elements
    int right_size = end - mid;
    int *tmp_right = new int[right_size];
    for(int i = 0; i < right_size; i++){
        tmp_right[i] = a[mid + 1 + i];
    }
    

    // Keep track of how many elements we've extraxted from each array
    int i = 0;
    int j = 0;

    // Keep track of whre we are inserting in final array
    int pos = start;

    // Picks the smaller element from the sub-arrays each iteration
    while((i < left_size) && (j < right_size)){
        // Merge in a left sub-list element if it's smaller
        if(tmp_left[i] <= tmp_right[j]){
            a[pos] = tmp_left[i];
            i++;
        // Merge in a right sub-list element if it's smaller
        }else{
            a[pos] = tmp_right[j];
            j++;
        }

        // Increment the insertion point each iteration
        pos++;
    }

    // Clean up remaining left-hand elements (if any)
    while(i < left_size){
        a[pos] = tmp_left[i];
        i++;
        pos++;
    }
    
    // Clean up remaining right-hand elements (if any)
    while(j < right_size){
        a[pos] = tmp_right[j];
        j++;
        pos++;
    }
    
}

// Merge Sort
// Takes:
//  a:      Array of usorting elements
//  left:   Left-hand index of sub-array
//  right:  Right-hand index of sub-array
// Returns:
//  NA
void merge_sort(int *a, int left, int right){
    // Split the array in half until there is a single element left
    if(left < right){
        // Calculate mid-point of array
        int mid = (left + right) / 2;

        // Sort the sub-vectors
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        // Merge the two sub-lists 
        merge(a, left, mid, right);
    }
}

// Quick Sort (Two functions)
// Partition
// Takes:
//  a:      Original array of elements being split into sub-arrays
//  left:   Starting point for sub-array
//  pivot:  Index of pivot element
// Returns:
//  Index of sorted pivot element
int partition(int *a, int left, int pivot){
    // Sub-array of "<=" starts before first index (contains nothing)
    int leq = left - 1;

    // Index of last element to sort into sub-list
    int high = pivot - 1;

    // Go over all elements in sub-array
    for(int j = left; j <= high; j++){
        // Does this element go in the "<=" sub-array?
        if(a[j] <= a[pivot]){
            // Move over marker of sub-array
            leq++;

            // Swap the element into position
            swap(&a[leq], &a[j]);
        }
    }

    // Move the pivot into the correct position between the sub-arrays
    swap(&a[leq + 1], &a[pivot]);

    // Return the index of sorted pivot
    return leq + 1;
}

// Quicksort
// Takes:
//  a:      Array of unsorted elements
//  left:   Start index of sub-array
//  pivot:  End index of sub-array
// Returns:
//  NA
void quicksort(int *array, int left, int pivot){
    // Recursively called until trivial sort of single element
    if(left < pivot){
        // Partition the array into "<=" and ">" sub-arrays
        int new_pivot = partition(array, left, pivot);

        // Sort the "<=" sub-array
        quicksort(array, left, new_pivot - 1);
        // Sort the ">" sub-array
        quicksort(array, new_pivot + 1, pivot);
    }
}

