#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &suspicious){
    suspicious[node] = true;
    for (int neighbor : adj[node]){
        if (!suspicious[neighbor]){
            dfs(neighbor, adj, suspicious);
        }
    }
}

vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations){
    vector<vector<int>> adj(n);
    for (auto &edge : invocations){
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> suspicious(n, false);
    dfs(k, adj, suspicious);

    for (auto &edge : invocations){
        int u = edge[0], v = edge[1];

        if (!suspicious[u] && suspicious[v]){
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                res.push_back(i);
            }
            return res;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++){
        if (!suspicious[i]){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    int n, k, m;
    cout << "Enter three integers: ";
    cin >> n >> k >> m;
    vector<vector<int>> invocations = {{1,2},{0,1},{3,2}};
    // vector<vector<int>> invocations(m, vector<int>(2));
    // cout << "Enter the invocations: " << endl;
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < 2; j++){
    //         cin >> invocations[i][j];
    //     }
    // }
    vector<int> result = remainingMethods(n, k, invocations);
    cout << "Remaining methods: ";
    for(int method : result){
        cout << method << " ";
    }

    return 0;
}