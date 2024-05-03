#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
};

// Find operation of disjoint sets
int find(DisjointSet& ds, int v) {
    if (ds.parent[v] != v)
        ds.parent[v] = find(ds, ds.parent[v]);
    return ds.parent[v];
}

// Union operation of disjoint sets
void Union(DisjointSet& ds, int x, int y) {
    int xroot = find(ds, x);
    int yroot = find(ds, y);

    if (ds.rank[xroot] < ds.rank[yroot])
        ds.parent[xroot] = yroot;
    else if (ds.rank[xroot] > ds.rank[yroot])
        ds.parent[yroot] = xroot;
    else {
        ds.parent[yroot] = xroot;
        ds.rank[xroot]++;
    }
}

// Function to perform Kruskal's algorithm
vector<Edge> kruskalMST(unordered_map<int, vector<pair<int, int>>>& graph) {
    vector<Edge> result;
    vector<Edge> edges;

    // Convert the graph into a vector of edges
    for (auto& it : graph) {
        int src = it.first;
        for (auto& edge : it.second) {
            int dest = edge.first;
            int weight = edge.second;
            edges.push_back({src, dest, weight});
        }
    }

    // Sort the edges in ascending order of their weights
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet ds;

    // Initialize disjoint set for each vertex
    for (auto& it : graph) {
        int v = it.first;
        ds.parent[v] = v;
        ds.rank[v] = 0;
    }

    // Process each edge in sorted order
    for (const auto& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;

        int srcRoot = find(ds, src);
        int destRoot = find(ds, dest);

        // If including this edge does not form a cycle, add it to the result
        if (srcRoot != destRoot) {
            result.push_back(edge);
            Union(ds, srcRoot, destRoot);
        }
    }

    return result;
}

int main() {
    // Create the graph using unordered map
    unordered_map<int, vector<pair<int, int>>> graph;

    // Add edges to the graph
    graph[0] = {{1, 5}, {3, 20}};
    graph[1] = {{0, 5}, {2, 5}};
    graph[2] = {{1, 5}, {3, 5}};
    graph[3] = {{0, 20}, {4, 1}};
    graph[4] = {{3, 1}, {5, 2},{6,4}};
    graph[5] = {{4, 2}, {6, 2}};
    graph[6] = {{4, 4}, {5, 2}};

    // Find the minimum spanning tree using Kruskal's algorithm
    vector<Edge> mst = kruskalMST(graph);

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}