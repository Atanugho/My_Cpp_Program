#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

void bellmanFord(unordered_map<int,vector<pair<int, int>>>& graph, int source) {
    unordered_map<int, int> distance;
    unordered_map<int, int> parent;

    // Initialize distances and parents
    for (const auto& pair : graph) {
        int vertex = pair.first;
        distance[vertex] = numeric_limits<int>::max();
        parent[vertex] = -1;
    }

    // Set distance of source vertex to 0
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < graph.size() - 1; ++i) {
        for (const auto& pair : graph) {
            int u = pair.first;
            for (const auto& edge : pair.second) {
                int v = edge.first;
                int weight = edge.second;
                if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& pair : graph) {
        int u = pair.first;
        for (const auto& edge : pair.second) {
            int v = edge.first;
            int weight = edge.second;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                cout << "Graph contains negative-weight cycle\n";
                return;
            }
        }
    }

    // Print shortest distances and paths
    for (const auto& pair : distance) {
        int vertex = pair.first;
        int dist = pair.second;
        cout << "Shortest distance from source to vertex " << vertex << ": " << dist << "\n";
        cout << "Path: ";
        int current = vertex;
        while (current != -1) {
            cout << current << " ";
            current = parent[current];
        }
        cout << "\n\n";
    }
}

int main() {
    
    unordered_map<int, vector<pair<int, int>>> graph;

    graph[0] = {{1, 4}, {2, 3}};
    graph[1] = {{3, 2}, {4, 5}};
    graph[2] = {{1, -2}};
    graph[3] = {{4, -1}};
    graph[4] = {{2, 6}};

    int source = 0; 

    bellmanFord(graph, source);

    return 0;
}