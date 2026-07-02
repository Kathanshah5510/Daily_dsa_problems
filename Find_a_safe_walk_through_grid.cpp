#include <bits/stdc++.h>
using namespace std;

int main(){
    int health;
    cout << "Enter your health: ";
    cin >> health;
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}};

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], {0, 0}});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty()){
        auto [cost, cell] = pq.top();
        pq.pop();
        int r = cell.first;
        int c = cell.second;
        if (cost > dist[r][c])
            continue;
        for (int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            int newCost = cost + grid[nr][nc];
            if (newCost < dist[nr][nc]){
                dist[nr][nc] = newCost;
                pq.push({newCost, {nr, nc}});
            }
        }
    }
    cout << (dist[m - 1][n - 1] < health ? "Safe walk possible." : "Safe walk not possible.");

    return 0;
}

