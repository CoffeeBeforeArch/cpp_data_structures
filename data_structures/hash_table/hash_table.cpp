// This program implements a simple hash table in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <list>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class HashTable{
private:
    // Number of buckets to store elements
    int buckets;

    // Pointer to said buckets
    list<int> *table;

public:
    // Simple constructor
    HashTable(int b){
        // Allocate space for the number of buckets asked for 
        buckets = b;
        table = new list<int>[buckets];
    }

    // insert into hash table
    void insert(int d);

    // Print out the hash table
    void print();
};


void HashTable::insert(int d){
    // Simple hash function is just modulo number of buckets
    int bucket = d % buckets;

    // Insert into hash table bucket
    table[bucket].push_back(d);
}

void HashTable::print(){
    for(int i = 0; i < buckets; i++){
        cout << "| Bucket " << i << " | ";
        for(auto j : table[i]){
            cout << "-> | " << j << " | ";
        }
        cout << endl;
    }
}

int main(){
    // Create a hash table with 8 buckets
    HashTable ht(8);

    // Set the random number seed
    srand(2);

    // Insert 20 random integers
    for(int i = 0; i < 20; i++){
        ht.insert(rand() % 100);
    }

    // Print the state of the hash table
    ht.print();

    return 0;
}
