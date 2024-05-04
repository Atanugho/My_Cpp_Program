#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Find the dsu

vector<int> parent;
vector<int> rank_;

int find(int x){

    if(x == parent[x]){
        return x;
    }

    return parent[x] = find(parent[x]);
}

void Union(int x,int y){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent){
        return ;
    }

    if(rank_[x_parent] > rank_[y_parent]){
        parent[y_parent] = x_parent;
    }
    else if(rank_[y_parent] > rank_[x_parent]){
        parent[x_parent] = y_parent;
    }
    else{
        parent[x_parent] = y_parent;
        rank_[y_parent]++;
    }

}

int kruskal(vector<vector<int>> &vec){


    int sum = 0;
    for(auto &temp : vec){
        int u = temp[0];
        int v = temp[1];
        int wt = temp[2];

        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u != parent_v) {
            Union(u,v);
            sum += wt;
        }
    }

    return sum;
}

int main() {
    
    unordered_map<int, vector<pair<int, int>>> graph;

    graph[0] = {{1, 5}, {3, 20}};
    graph[1] = {{0, 5}, {2, 5}};
    graph[2] = {{1, 5}, {3, 5}};
    graph[3] = {{0, 20}, {4, 1}};
    graph[4] = {{3, 1}, {5, 2},{6,4}};
    graph[5] = {{4, 2}, {6, 2}};
    graph[6] = {{4, 4}, {5, 2}};

    parent.resize(graph.size());
    rank_.resize(graph.size(),0);

    for(int i = 0;i < graph.size();i++){
        parent[i] = i;
    }

    vector<vector<int>> vec;

    for(int u = 0; u < graph.size();u++){

        for(auto &temp : graph[u]){

            int v = temp.first;
            int wt = temp.second;

            vec.push_back({u,v,wt});
        }
    }

    auto comp = [&](vector<int> &vec1,vector<int> &vec2){

        return vec1[2] < vec2[2];
    };

    sort(begin(vec),end(vec),comp);

    cout <<"Weight Of The Minimum Spanning Tree is -" << kruskal(vec) << endl;

    return 0;

}