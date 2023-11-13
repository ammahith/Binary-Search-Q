#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to perform DFS traversal
bool dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, int parent) {
    visited[v] = true;

    // Traverse all adjacent vertices of v
    for (int u : graph[v]) {
        if (!visited[u]) {
            if (dfs(u, graph, visited, v))
                return true;
        }
        else if (u != parent) {
            // If u is visited and not the parent of v, it forms a cycle
            return true;
        }
    }

    return false;
}

// Function to check if a graph contains a cycle
bool isCyclic(int V, vector<pair<int, int>>& edges) {
    // Create an adjacency list representation of the graph
    vector<vector<int>> graph(V);

    // Add edges to the graph
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Create a visited array to keep track of visited vertices
    vector<bool> visited(V, false);

    // Perform DFS traversal starting from each unvisited vertex
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            if (dfs(v, graph, visited, -1))
                return true;
        }
    }

    return false;
}

int main() {
    int V = 3; // Number of vertices

    vector<pair<int, int>> edges = { {1, 2}, {0, 1}, {2, 0} }; // Edges of the graph

    bool hasCycle = isCyclic(V, edges);

    cout << (hasCycle ? "Cyclic" : "Not Cyclic") << endl;

    return 0;
}