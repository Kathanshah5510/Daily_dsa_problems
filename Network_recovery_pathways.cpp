#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

int main(){
    vector<vector<int>> edges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
    vector<bool> online = {true, true, true, true};
    long long k = 10;

    int n = online.size();
    vector<vector<pair<int, int>>> graph(n);

    int low = INT_MAX, high = 0;

    // Build graph (skip offline intermediate nodes)
    for (auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        if ((u != 0 && u != n - 1 && !online[u]) || (v != 0 && v != n - 1 && !online[v]))
            continue;

        graph[u].push_back({v, w});

        low = min(low, w);
        high = max(high, w);
    }

    if (low == INT_MAX)
        return -1;

    auto check = [&](int limit){
        vector<ll> dist(n, INF);
        priority_queue<pair<ll, int>,
                       vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto &[v, w] : graph[u]){
                if (w < limit)
                    continue;

                if (dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    };

    if (!check(low))
        return -1;

    int ans = low;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (check(mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << "The minimum weight is: " << ans << endl;

    return 0;
}