// This program implements the Dijkstra algorithm in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <list>
#include <utility>

using namespace std;

class Graph{
private:
    // Number of vertices
    int V;
    // Pointer to adjacency list
    list<pair<int, int>> *adj;

public:
    // Constructor prototype
    Graph(int v);

    // Method to add an edge/weight pair
    void addEdge(int v1, int v2, int weight);

};

// Constructer with number of vertices
Graph::Graph(int v){
    // Set number of vertices
    V = v;

    // Create new adjacency list
    adj = new list<pair<int, int>>[v];
}

// Implementation of method to add edges
void Graph::addEdge(int v1, int v2, int weight){
    adj[v1].push_back(make_pair(v2, weight));
}

int main(){
    // Create a graph
    Graph g(9);

    // Gives some edges and weights to the vertices
    // Add node 0
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    
    // Add node 1
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    
    // Add node 2
    g.addEdge(2, 1, 8);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 3, 7);

    // Add node 3
    g.addEdge(3, 2, 7);
    g.addEdge(3, 5, 14);
    g.addEdge(3, 4, 9);

    // Add node 4
    g.addEdge(4, 3, 9);
    g.addEdge(4, 5, 10);
    
    // Add node 5
    g.addEdge(5, 6, 2);
    g.addEdge(5, 2, 4);
    g.addEdge(5, 3, 14);
    g.addEdge(5, 4, 10);
    
    // Add node 6
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(6, 5, 2);

    // Add node 7
    g.addEdge(7, 0, 8);
    g.addEdge(7, 1, 11);
    g.addEdge(7, 8, 7);
    g.addEdge(7, 6, 1);

    // Add node 8
    g.addEdge(8, 2, 2);
    g.addEdge(8, 7, 7);
    g.addEdge(8, 6, 6);

    return 0;
}
