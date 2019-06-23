// This program shows off a basic DFS implementation in C++
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
    // DFS recursive helper functions
    void DFS_helper(int s, bool *visited);

public:
    // Constructor prototype
    Graph(int v);

    // Method to add an edge
    void addEdge(int v, int w);

    // Method for BFS traversal give a source "s"
    void DFS(int s);
};

// Constructer with number of vertices
Graph::Graph(int v){
    // Set number of verticest
    V = v;

    // Create new adjacency list
    adj = new list<int>[v];
}

// Implementation of method to add edges
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS_helper(int s, bool *visited){
    // Mark the current node as visited
    cout << "Visiting node " << s << endl;
    visited[s] = true;

    // Go through the adjacency list
    for(auto i = adj[s].begin(); i != adj[s].end(); i++){
        // If not visited, travel through that vertex
        if(!visited[*i]){
            DFS_helper(*i, visited);
        }
    }
}

// Perform BFS given a starting vertex
void Graph::DFS(int s){
    // Start with all vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    // Beginning of recursive call
    DFS_helper(s, visited);
}

int main(){
    // Create a new graph
    Graph g(6);

    // Create some edges to the vertices
    // Connections for vertex 0
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    // Connections for vertex 1
    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // Connections for vertex 2
    g.addEdge(2, 0);
    g.addEdge(2, 4);

    // Connections for vertex 3
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    // Connections for vertex 4
    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);

    // Connections for vertex 5
    g.addEdge(5, 3);
    g.addEdge(5, 4);

    // Perform BFS and print result
    g.DFS(0);
    
    return 0;
}
