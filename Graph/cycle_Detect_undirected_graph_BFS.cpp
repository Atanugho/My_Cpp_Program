
bool isCycleBFS(vector<int> adj[],int u,vector<bool> &visited){

    queue<pair<int,int>> qu;

    qu.push({u,-1});
    visited[u] = true;

    while(!qu.empty()){
        pair<int,int> p = qu.front();
        qu.pop();

        int source = p.first;
        int parent = p.second;

        for(int &v : adj[source]){

            if(visited[v] == false){
                visited[v] = true;
                qu.push({v,source});
            }else if(v != parent) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V,vector<int> adj[]){

    vector<bool> visited(V,false);

    for(int  i = 0 ;i < V ;i++){

        if(!visited[i] && isCycleBFS(adj,i,visited)){
            return true;
        }
    }

    return false;
}