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

// explain this code
// This C++ program is designed to determine if a safe walk through a grid is possible given a certain amount of health. The grid is represented as a 2D vector where each cell can either be safe (0) or dangerous (1). The goal is to find the minimum cost path from the top-left corner of the grid (0,0) to the bottom-right corner (m-1,n-1), where the cost is defined by the number of dangerous cells encountered along the path.
// The program uses Dijkstra's algorithm to find the shortest path in terms of cost. It initializes a distance matrix `dist` to keep track of the minimum cost to reach each cell, starting with the top-left corner. A priority queue is used to explore the cells with the lowest cost first.
// The program iterates through the grid, checking each neighboring cell (up, down, left, right) and updating the cost if a cheaper path is found. If the minimum cost to reach the bottom-right corner is less than the given health, it outputs that a safe walk is possible; otherwise, it indicates that a safe walk is not possible.

// dry run
// Let's dry run the code with an example input. Assume the user inputs a health value of 3.
// The grid is as follows:
// {0, 1, 0, 0, 0},
// {0, 1, 0, 1, 0},
// {0, 0, 0, 1, 0}
// what happens step by step:
// 1. The program initializes the grid and reads the health value (3).
// 2. It sets up the distance matrix `dist` with all values initialized to `INT_MAX`, except for the starting cell (0,0) which is set to 0 (the cost of the starting cell).
// 3. The priority queue is initialized with the starting cell (0,0) and its cost (0).
// 4. The program enters the while loop, where it processes cells from the priority queue based on their cost. It pops the cell with the lowest cost (initially (0,0) with cost 0).
// 5. It checks the neighboring cells of (0,0):
//    - (1,0): Safe (0), new cost = 0 + 0 = 0. Update `dist[1][0]` to 0 and push (1,0) into the queue.
//    - (0,1): Dangerous (1), new cost = 0 + 1 = 1. Update `dist[0][1]` to 1 and push (0,1) into the queue.
//    - (-1,0) and (0,-1) are out of bounds, so they are ignored.
// 6. The next cell popped from the queue is (1,0) with cost 0. It checks its neighbors:
//    - (0,0): Already visited with cost 0, no update needed.
//    - (2,0): Safe (0), new cost = 0 + 0 = 0. Update `dist[2][0]` to 0 and push (2,0) into the queue.
//    - (1,1): Dangerous (1), new cost = 0 + 1 = 1. Update `dist[1][1]` to 1 and push (1,1) into the queue.
//    - (1,-1) is out of bounds, so it is ignored.
// 7. The next cell popped from the queue is (0,1) with cost 1. It checks its neighbors:
//    - (1,1): Already visited with cost 1, no update needed.
//    - (0,2): Safe (0), new cost = 1 + 0 = 1. Update `dist[0][2]` to 1 and push (0,2) into the queue.
//    - (-1,1) and (0,0) are either out of bounds or already visited, so they are ignored.
// 8. The next cell popped from the queue is (2,0) with cost 0. It checks its neighbors:
//    - (1,0): Already visited with cost 0, no update needed.
//    - (2,1): Safe (0), new cost = 0 + 0 = 0. Update `dist[2][1]` to 0 and push (2,1) into the queue.
//    - (3,0) is out of bounds, so it is ignored.
// 9. The next cell popped from the queue is (1,1) with cost 1. It checks its neighbors:
//    - (0,1): Already visited with cost 1, no update needed.
//    - (2,1): Already visited with cost 0, no update needed.
//    - (1,2): Dangerous (1), new cost = 1 + 1 = 2. Update `dist[1][2]` to 2 and push (1,2) into the queue.
//    - (1,0): Already visited with cost 0, no update needed.
//10. The next cell popped from the queue is (0,2) with cost 1. It checks its neighbors:
    // - (1,2): Already visited with cost 2, no update needed.
    // - (0,3): Safe (0), new cost = 1 + 0 = 1. Update `dist[0][3]` to 1 and push (0,3) into the queue.
    // - (-1,2) and (0,1) are either out of bounds or already visited, so they are ignored.
//11. The next cell popped from the queue is (2,1) with cost 0. It checks its neighbors:
    // - (1,1): Already visited with cost 1, no update needed.
    // - (2,2): Safe (0), new cost = 0 + 0 = 0. Update `dist[2][2]` to 0 and push (2,2) into the queue.
    // - (3,1) is out of bounds, so it is ignored.
    // - (2,0): Already visited with cost 0, no update needed.
//12. The next cell popped from the queue is (1,2) with cost 2. It checks its neighbors:
    // - (0,2): Already visited with cost 1, no update needed.