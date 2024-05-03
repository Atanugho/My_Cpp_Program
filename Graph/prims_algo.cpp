#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;


void primMST(const unordered_map<int, vector<pair<int, int>>>& graph, int startVertex) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> key(graph.size(), INT_MAX); //weight

    vector<int> parent(graph.size(), -1);

    vector<bool> inMST(graph.size(), false);

    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (auto& neighbor : graph.at(u)) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                // Update the key value of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < graph.size(); i++) {
        cout << parent[i] << " - " << i << endl;
    }
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

    int startVertex = 0;

    primMST(graph, startVertex);

    return 0;
}