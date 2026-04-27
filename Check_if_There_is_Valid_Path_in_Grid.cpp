#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        vector<vector<int>> dirs = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        vector<int> opposite = {1, 0, 3, 2};

        unordered_map<int, vector<int>> mp = {
            {1, {2, 3}},
            {2, {0, 1}},
            {3, {2, 1}},
            {4, {3, 1}},
            {5, {2, 0}},
            {6, {3, 0}}
        };

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == n-1 && y == m-1) return true;

            for(int dir : mp[grid[x][y]]) {
                int nx = x + dirs[dir][0];
                int ny = y + dirs[dir][1];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(vis[nx][ny]) continue;

                for(int back : mp[grid[nx][ny]]) {
                    if(back == opposite[dir]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << (sol.hasValidPath(grid) ? "true" : "false") << endl;

    return 0;
}