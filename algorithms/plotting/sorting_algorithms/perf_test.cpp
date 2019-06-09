// This program is for collecting performance data for each of the
// implemented sorting algorithms with across arange of input sizes
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <fstream>
#include <vector>

// Location of all sorting algorithms/utilities
#include "common.h"

int main(){
    // Number iterations per-sample point (default 10k)
    int N = 100;

    // Starting input size
    int lower = 10;

    // Upper bound on input-size to test
    int upper = 1000;

    // Pointer to the array of unsorted elements
    int *a;

    // Average time for sorting an input size
    double time;

    // Vector to store all average times
    vector<double> times;

    // Run each input size N times
    for(int i = lower; i < upper; i++){
        // Allocate a new array for each size
        a = new int[i];

        // Run this array size with N different inputs
        for(int j = 0; j < N; j++){
            // Re-initialize the array with new random values
            init_array(a, i);

            // Get start time
            auto start = get_time();

            // Sorting algorithm profile
            insertion_sort(a, i);
            //selection_sort(a, i);
            //bubble_sort(a, i);
            //quicksort(a, 0, i - 1);            
            //merge_sort(a, 0, i - 1);            

            // Get end time
            auto end = get_time();

            // Calculate duration
            auto span = duration_cast<duration<double>>(end - start);

            // Add to the total time
            time += span.count();
        }

        // Compute average time and store it in the vector
        times.push_back(time / N);

        // Free the array after we are done with it
        delete [] a;
    }

    // Write out the times to a data file
    ofstream output_file;
    output_file.open("timing.dat", ios::out | ios::trunc);
    for(auto i : times){
        output_file << i << "\n"; 
    }

    return 0;
}
