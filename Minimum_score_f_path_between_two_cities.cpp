#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, int &ans){
    vis[node] = 1;
    for (auto &[next, wt] : adj[node]){
        ans = min(ans, wt);
        if (!vis[next])
            dfs(next, adj, vis, ans);
    }
}

int main(){
    int n = 4;
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &road : roads){
        int u = road[0];
        int v = road[1];
        int w = road[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> vis(n + 1, 0);
    int ans = INT_MAX;
    dfs(1, adj, vis, ans);
    cout << "The minimum score of a valid path is: " << ans << endl;

    return 0;
}