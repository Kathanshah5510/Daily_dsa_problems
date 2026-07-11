#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int &nodes, int &degreeSum){
    vis[node] = true;
    nodes++;
    degreeSum += adj[node].size();
    for (int nei : adj[node]){
        if (!vis[nei])
            dfs(nei, adj, vis, nodes, degreeSum);
    }
}

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    vector<vector<int>> adj(n);
    for (auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (vis[i])
            continue;

        int nodes = 0;
        int degreeSum = 0;
        dfs(i, adj, vis, nodes, degreeSum);
        int edgeCount = degreeSum / 2;
        if (edgeCount == nodes * (nodes - 1) / 2)
            ans++;
    }
    cout << "Number of complete components: " << ans << endl;

    return 0;
}