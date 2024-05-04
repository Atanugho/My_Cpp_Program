#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct DSU {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
};

int find(DSU& ds, int v) {
    if (ds.parent[v] != v)
        ds.parent[v] = find(ds, ds.parent[v]);
    return ds.parent[v];
}

void Union(DSU& ds, int x, int y) {
    int x_parent = find(ds, x);
    int y_parent = find(ds, y);

    if (ds.rank[x_parent] < ds.rank[y_parent])
        ds.parent[x_parent] = y_parent;
    else if (ds.rank[x_parent] > ds.rank[y_parent])
        ds.parent[y_parent] = x_parent;
    else {
        ds.parent[y_parent] = x_parent;
        ds.rank[x_parent]++;
    }
}

vector<Edge> kruskalMST(unordered_map<int, vector<pair<int, int>>>& graph) {
    vector<Edge> result;
    vector<Edge> edges;

    for (auto& it : graph) {
        int src = it.first;
        for (auto& edge : it.second) {
            int dest = edge.first;
            int weight = edge.second;
            edges.push_back({src, dest, weight});
        }
    }

    
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU ds;

    //initialisze rank = 0 and parent itslef and find edge
    for (auto& it : graph) {
        int v = it.first;
        ds.parent[v] = v;
        ds.rank[v] = 0;
    }

    int sum = 0;

    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int wt = edge.weight;

        int parent_u = find(ds, u);
        int parent_v = find(ds, v);

        // If including this edge does not form a cycle, add it to the result
        if (parent_u != parent_v) {
            result.push_back(edge);
            sum += wt;
            Union(ds, parent_u, parent_v);
        }

    }

    cout << "Minimum Cost Of Minimum Spanning Tree:" << sum<<"\n";

    return result;
}

int main() {
    
    unordered_map<int, vector<pair<int, int>>> graph;

    graph[0] = {{1, 5}, {3, 20}};
    graph[1] = {{0, 5}, {2, 5}};
    graph[2] = {{1, 5}, {3, 5}};
    graph[3] = {{0, 20}, {4, 1}};
    graph[4] = {{3, 1}, {5, 2},{6,4}};
    graph[5] = {{4, 2}, {6, 2}};
    graph[6] = {{4, 4}, {5, 2}};

    vector<Edge> mst = kruskalMST(graph);

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}