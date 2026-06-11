#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long modPow(long long a, long long b){
    long long res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int maxDepthTree(vector<vector<int>>& adj, int n){
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(1);
    vis[1] = 1;
    int depth = -1;
    while (!q.empty()) {
        int sz = q.size();
        depth++;
        while (sz--) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return depth;
}

long long assignEdgeWeights(vector<vector<int>>& edges){
    int n = edges.size() + 1;
    vector<vector<int>> adj(n + 1);
    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int depth = maxDepthTree(adj, n);
    return modPow(2, depth - 1);
}

int main(){
    int m;   
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << assignEdgeWeights(edges) << '\n';

    return 0;
}