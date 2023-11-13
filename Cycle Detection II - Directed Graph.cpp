#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
bool dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recursionStack) {
    visited[v] = true;
    recursionStack[v] = true;

    // Traverse all adjacent vertices of v
    for (int u : graph[v]) {
        if (!visited[u]) {
            if (dfs(u, graph, visited, recursionStack))
                return true;
        }
        else if (recursionStack[u]) {
            // If u is visited and present in the recursion stack, it forms a cycle
            return true;
        }
    }

    recursionStack[v] = false;

    return false;
}

// Function to check if a directed graph contains a cycle
bool isCyclic(int V, vector<pair<int, int>>& edges) {
    // Create an adjacency list representation of the graph
    vector<vector<int>> graph(V);

    // Add edges to the graph
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
    }

    // Create a visited array to keep track of visited vertices
    vector<bool> visited(V, false);
    // Create a recursion stack to keep track of vertices in the current recursion stack
    vector<bool> recursionStack(V, false);

    // Perform DFS traversal starting from each unvisited vertex
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            if (dfs(v, graph, visited, recursionStack))
                return true;
        }
    }

    return false;
}

int main() {
    int V = 3; // Number of vertices

    vector<pair<int, int>> edges = { {1, 2}, {2, 0}, {0, 1} }; // Edges of the graph

    bool hasCycle = isCyclic(V, edges);

    cout << (hasCycle ? "Cyclic" : "Not Cyclic") << endl;

    return 0;
}
