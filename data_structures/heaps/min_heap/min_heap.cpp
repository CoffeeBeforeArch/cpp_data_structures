// This program implements a min heap in C++
// By: Nick from CoffeeBeforeArch

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Class for a minimum heap implementation
class minHeap{
private:
    // Current size of the heap
    int size;
    // Max size of heap
    int capacity;
    // Store elements as a vector
    vector<int> heap;
    // Returns the parent index
    int parent(int i){return (i - 1) / 2;}
    // Returns the left child
    int left(int i){return 2 * i + 1;}
    // Returns the right child
    int right(int i){return 2 * i + 2;}

public:
    // Constructor
    minHeap(int capacity);
    // Insert a key into the min heap
    void insert(int k);
    // Extracts the minumum element
    int extractMin();
    // Recursively heapify a sub-tree
    void heapify(int i);
    // Print the heap
    void printHeap();
};

// Consturctor that sets the heap size and capacity
minHeap::minHeap(int capacity){
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

// Insert key into the minHeap
void minHeap::insert(int k){
    // Make sure there is still space in the heap
    if(size == capacity){
        cout << "MIN HEAP FULL!" << endl;
        return;
    }

    // Increse the amount of elements in the heap
    size++;

    // Insert the new key at the end
    int i = size - 1;
    heap[i] = k;

    // Fix the min heap property
    // Moves the element up until i >= parent or root
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// Recursive function to maintain structure
void minHeap::heapify(int i){
    // Set initial conditions
    int l = left(i);
    int r = right(i);
    int smallest = i;

    // Find the smallest element of the three
    if((l < size) && (heap[l] < heap[smallest])){
        smallest = l;
    }if((r < size) && (heap[r] < heap[smallest])){
        smallest = r;
    }

    // If the smallest of l or r, continue heapify
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

// Removes the smallest element and fixes the order
int minHeap::extractMin(){
    // Check if the heap is empty
    if(size == 0){
        cout << "EMPTY HEAP" << endl;
        return -1;
    // Check if there is only 1 element
    }else if(size == 1){
        size--;
        return heap[0];
    // Normal extraction
    }else{
        // Store the root
        int root = heap[0];

        // Maintain heap shape and then order
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        // Return min element
        return root;
    }
}

// Print the heap in a pretty format
void minHeap::printHeap(){
    int power = 0;
    int value = 1;
    for(int i = 0; i < size; i++){
        if(i == value){
            cout << endl;
            power += 1;
            value += (1 << power);
        }
        cout << heap[i] << "  ";
    }
    cout << endl;
}

int main(){
    // Number of elements for our minHeap
    int N = 15;

    // Declare a heap with space for 10 elements
    minHeap heap(N);

    // Insert N random numbers
    for(int i = 0; i < N; i++){
        cout << "Inserting element " << i+1 << endl;
        heap.insert(rand() % 100);
        heap.printHeap();
        cout << endl;
    }

    return 0;
}
