vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<int> result(V, INT_MAX);

	result[S] = 0;
	pq.push({0, S});
	//NOTE - You can add a visited vector to avoid revisiting a node again and again. It will reduce the time complexity.

		while(!pq.empty()) {

			int d  = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			for(auto &vec : adj[node]) {

				int adjNode = vec[0];
				int dist    = vec[1];

				if(d + dist < result[adjNode]) {

					result[adjNode] = d + dist;
					pq.push({d+dist, adjNode});

				}

			}

		}

	return result;

	}
};