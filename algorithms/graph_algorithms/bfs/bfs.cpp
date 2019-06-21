// This program shows off a basic BFS implementation in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
    // Number of vertices
    int V;
    // Pointer to adjacency list
    list<int> *adj;

public:
    // Constructor prototype
    Graph(int v);

    // Method to add an edge
    void addEdge(int v, int w);

    // Method for BFS traversal give a source "s"
    void BFS(int s);
};

// Constructer with number of vertices
Graph::Graph(int v){
    // Set number of verticest
    V = v;

    // Create new adjacency list
    adj = new list<int>[v]
}

// Implementation of method to add edges
Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

int main(){

}
