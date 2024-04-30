#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCycle(vector<vector<int>>& graph, vector<int>& inDegree) {
	int n = graph.size();
	vector<int> result;
	queue<int> q;

    int count = 0;
	// Enqueue all nodes with in-degree 0
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
            count++;
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		result.push_back(u);

		// Reduce in-degree of adjacent nodes
		for (int v : graph[u]) {
			inDegree[v]--;
			if (inDegree[v] == 0) {
				q.push(v);
                count++;
			}
		}
	}

    if (count == n){
        return false;
    }else{
        return true;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    

    if (isCycle) {
        cout << "Cycle detected in the directed graph.\n";
    } else {
        cout << "No cycle detected in the directed graph.\n";
    }

    return 0;
}