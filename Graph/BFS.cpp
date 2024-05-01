#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void bfs(const unordered_map<int, vector<int>>& graph, int start) {
    unordered_map<int, bool> visited;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : graph.at(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<int, vector<int>> graph;

    // Add edges to the graph
    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3, 4};

    int startNode = 2;

    cout << "BFS traversal starting from node " << startNode << ": ";
    bfs(graph, startNode);

    return 0;
}