#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclic(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = curr;
            } else if (parent[curr] != neighbor) {
                // If the neighbor is already visited and not the parent of the current node,
                // then there is a cycle in the graph.
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    if (isCyclic(graph, start)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle detected in the graph.\n";
    }

    return 0;
}