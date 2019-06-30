// This program implements a min heap in C++
// By: Nick from CoffeeBeforeArch

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

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
    void insertKey(int k);
    // Extracts the minumum element
    int extractMin();
    // Deletes a key in the min heap
    void deleteKey(int k);
    // Recursively heapify a sub-tree
    void minHeapify(int i);
};

// Consturctor that sets the heap size and capacity
minHeap::minHeap(int capacity){
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

// Insert key into the minHeap
void minHeap::insertKey(int k){
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
}

int main(){
    // Number of elements for our minHeap
    int N = 10;

    // Declare a heap with space for 10 elements
    minHeap heap(N);

    return 0;
}
