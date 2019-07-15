// This program implements the Dijkstra algorithm in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>

#define INF 1000000

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
    // Method for shortest path
    void shortestPath(int s);
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

// Implemenation of method to find the shortest paths
void Graph::shortestPath(int s){
    // Create set to store vertices
    // Use this to extract the shortest path
    set<pair<int, int>> extract_set;

    // Vector for distances
    // All paths are initialized to a large value
    vector<int> distances(V, INF);

    // Insert the entry point into the set
    // Initialize distance to 0
    extract_set.insert(make_pair(0, s));
    distances[s] = 0;

    // Continue until all shortest distances are finalized
    while(!extract_set.empty()){
        // Extract the minimum distances
        pair<int, int> tmp = *(extract_set.begin());
        extract_set.erase(extract_set.begin());

        // Get the vertex number
        int u = tmp.second;

        // Go over the adjacency list
        for(auto i = adj[u].begin(); i != adj[u].end(); i++){
            // Get the vertex and weight
            int v = (*i).first;
            int weight = (*i).second;

            // Check if we have found a shorter path to v
            if(distances[v] > distances[u] + weight){
                // Remove the current distance if it is greater
                extract_set.erase(extract_set.find(make_pair(distances[v], v)));
            }

            // Update the distance
            distances[v] = distances[u] + weight;
            extract_set.insert(make_pair(distances[v], v));
        }
    }

}

int main(){
    // Create a graph
    Graph g(9);

    // Gives some edges and weights to the vertices
    // Add node 0
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    
    // Add node 1
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    
    // Add node 2
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 3, 7);

    // Add node 3
    g.addEdge(3, 5, 14);
    g.addEdge(3, 4, 9);

    // Add node 4
    g.addEdge(4, 5, 10);
    
    // Add node 5
    g.addEdge(5, 6, 2);
    
    // Add node 6
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);

    // Add node 7
    g.addEdge(7, 8, 7);

    // Add node 8

    g.shortestPath(0);
    return 0;
}
