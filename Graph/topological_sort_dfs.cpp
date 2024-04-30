#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& graph, stack<int>& st) {
	visited[u] = true;

	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, visited, graph, st);
		}
	}

	st.push(u);
}

vector<int> topologicalSort(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<bool> visited(n, false);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, visited, graph, st);
		}
	}

	vector<int> result;
	while (!st.empty()) {
		result.push_back(st.top());
		st.pop();
	}

	return result;
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