#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(vector<vector<int>>& graph, int v, vector<bool>& visited, vector<bool>& recursionStack) {
    if (!visited[v]) {
        visited[v] = true;
        recursionStack[v] = true;

        for (int i = 0; i < graph[v].size(); i++) {
            int neighbor = graph[v][i];
            if (!visited[neighbor] && isCyclicUtil(graph, neighbor, visited, recursionStack))
                return true;
            else if (recursionStack[neighbor])
                return true;
        }
    }

    recursionStack[v] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    vector<bool> recursionStack(numVertices, false);

    for (int i = 0; i < numVertices; i++) {
        if (isCyclicUtil(graph, i, visited, recursionStack))
            return true;
    }

    return false;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
    }

    if (isCyclic(graph, numVertices))
        cout << "The graph contains a cycle." << endl;
    else
        cout << "The graph does not contain a cycle." << endl;

    return 0;
}