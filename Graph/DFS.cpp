#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> visited;

    // Add edges to the graph
    graph[1] = {2, 3};
    graph[2] = {4, 5};
    graph[3] = {6};
    graph[4] = {};
    graph[5] = {7};
    graph[6] = {};
    graph[7] = {};

    // Initialize visited map
    for (auto& pair : graph) {
        visited[pair.first] = false;
    }

    // Perform DFS starting from node 1
    dfs(1, graph, visited);

    return 0;
}