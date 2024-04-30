#include <iostream>
#include <vector>


using namespace std;

bool isCyclicDFS(vector<vector<int>>& graph, int v, vector<bool>& visited, vector<bool>& recursionStack) {
    if (!visited[v]) {
        visited[v] = true;
        recursionStack[v] = true;

        for (int i = 0; i < graph[v].size(); i++) {
            int neighbor = graph[v][i];
            if (!visited[neighbor] && isCyclicDFS(graph, neighbor, visited, recursionStack))
                return true;
            else if (recursionStack[neighbor])
                return true;
        }
    }

    recursionStack[v] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    vector<bool> recursionStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicDFS(graph, i, visited, recursionStack))
            return true;
    }

    return false;
}

int main() {
    int V, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(V);

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
    }

    if (isCyclic(graph, V))
        cout << "The graph contains a cycle." << endl;
    else
        cout << "The graph does not contain a cycle." << endl;

    return 0;
}