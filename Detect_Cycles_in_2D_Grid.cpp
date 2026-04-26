#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<bool>> vis;

bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
    vis[x][y] = true;

    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        // boundary check
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        // must be same character
        if (grid[nx][ny] != grid[x][y]) continue;

        if (!vis[nx][ny]) {
            if (dfs(nx, ny, x, y, grid)) return true;
        } 
        else if (nx != px || ny != py) {
            return true;
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                if (dfs(i, j, -1, -1, grid)) return true;
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bool result = containsCycle(grid);

    if (result) cout << "true\n";
    else cout << "false\n";

    return 0;
}