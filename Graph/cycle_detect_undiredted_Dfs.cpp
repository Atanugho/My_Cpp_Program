#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(vector<vector<int>>& graph, int v, vector<bool>& visited, int parent) {
    visited[v] = true;

    for (int i = 0; i < graph[v].size(); i++) {
        int neighbor = graph[v][i];

        if (!visited[neighbor]) {
            if (isCyclicUtil(graph, neighbor, visited, v))
                return true;
        }
        else if (neighbor != parent)
            return true;
    }

    return false;
}

bool isCyclic(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<bool> visited(V, false);

    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            if (isCyclicUtil(graph, v, visited, -1))
                return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isCyclic(graph))
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph does not contain a cycle." << endl;

    return 0;
}