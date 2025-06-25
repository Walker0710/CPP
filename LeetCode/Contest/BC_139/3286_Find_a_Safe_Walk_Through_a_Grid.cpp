#include <bits/stdc++.h>

using namespace std;

// << ,

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool solve(int i, int j, vector<vector<int>> &grid, int health, vector<vector<bool>> &visited, vector<vector<unordered_map<int, bool>>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || health <= 0)
        return false;

    if (dp[i][j].count(health))
        return dp[i][j][health];

    if (i == n - 1 && j == m - 1 && grid[i][j] == 1 && health <= 1)
        return dp[i][j][health] = false;

    if (i == n - 1 && j == m - 1)
        return dp[i][j][health] = true;

    visited[i][j] = true;

    for (auto [dx, dy] : dir)
    {
        int row = i + dx;
        int col = j + dy;

        if (solve(row, col, grid, health - grid[i][j], visited, dp))
            return dp[i][j][health] = true;
    }

    visited[i][j] = false;
    return dp[i][j][health] = false;
}

bool findSafeWalk(vector<vector<int>> &grid, int health)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<unordered_map<int, bool>>> dp(n, vector<unordered_map<int, bool>>(m));

    return solve(0, 0, grid, health, visited, dp);
}
