#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph, stack<int>& result) {
	visited[node] = true;

	for (int neighbor : graph[node]) {
		if (!visited[neighbor]) {
			dfs(neighbor, visited, graph, result);
		}
	}

	result.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<bool> visited(n, false);
	stack<int> result;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, visited, graph, result);
		}
	}

	vector<int> sorted;
	while (!result.empty()) {
		sorted.push_back(result.top());
		result.pop();
	}

	return sorted;
}

int main() {
	int n, m;
	cout << "Enter the number of nodes: ";
	cin >> n;
	cout << "Enter the number of edges: ";
	cin >> m;

	vector<vector<int>> graph(n);

	cout << "Enter the edges:\n";
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	vector<int> sorted = topologicalSort(graph);

	cout << "Topological Sort: ";
	for (int node : sorted) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}