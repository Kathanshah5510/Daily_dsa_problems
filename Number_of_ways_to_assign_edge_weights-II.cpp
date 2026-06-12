#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;
int LOG;

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int u, int p) {
    up[0][u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; k++) {
        if (diff & (1 << k))
            u = up[k][u];
    }
    if (u == v)
        return u;
    for (int k = LOG - 1; k >= 0; k--) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }
    return up[0][u];
}

vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size() + 1;
    adj.assign(n + 1, {});
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    up.assign(LOG, vector<int>(n + 1));
    depth.assign(n + 1, 0);
    dfs(1, 1);
    for (int k = 1; k < LOG; k++) {
        for (int v = 1; v <= n; v++) {
            up[k][v] = up[k - 1][ up[k - 1][v] ];
        }
    }

    vector<int> ans;
    for (auto &q : queries) {
        int u = q[0];
        int v = q[1];
        int w = lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[w];
        ans.push_back((int)modPow(2, dist - 1));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = assignEdgeWeights(edges, queries);
    for (int x : ans)
        cout << x << " ";
    cout << '\n';
    return 0;
}