#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int j, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp)
{
    if (i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int row = INT_MIN;
    int col = INT_MIN;

    // move down
    for (int p = i + 1; p < n; p++)
    {
        row = max(row, grid[p][j] - grid[i][j] + solve(p, j, grid, n, m, dp));
    }

    // move right
    for (int q = j + 1; q < m; q++)
    {
        col = max(col, grid[i][q] - grid[i][j] + solve(i, q, grid, n, m, dp));
    }

    return dp[i][j] = max(0, max(row, col));
}

int maxScore(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = INT_MIN;

    int alter = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, solve(i, j, grid, n, m, dp));

            if (i + 1 < n)
                alter = max(alter, grid[i + 1][j] - grid[i][j]);

            if (j + 1 < m)
                alter = max(alter, grid[i][j + 1] - grid[i][j]);
        }
    }

    if (ans == 0)
        return alter;

    return ans;
}

int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= grid.size() || j >= grid[0].size())
    return 0;
    
    if (dp[i][j] != -1)
    return dp[i][j];

    int pick1 = INT_MIN, pick2 = INT_MIN;

    if (i + 1 < grid.size())
    pick1 = grid[i + 1][j] - grid[i][j] + solve(i + 1, j, grid, dp);
    
    if (j + 1 < grid[0].size())
    pick2 = grid[i][j + 1] - grid[i][j] + solve(i, j + 1, grid, dp);

    dp[i][j] = max(0, max(pick1, pick2));

    return dp[i][j];
}

int maxScore(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxi = INT_MIN;
    int maxi1 = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxi = max(maxi, solve(i, j, grid, dp));

            if (i + 1 < m)
            maxi1 = max(maxi1, grid[i + 1][j] - grid[i][j]);
            
            if (j + 1 < n)
            maxi1 = max(maxi1, grid[i][j + 1] - grid[i][j]);
        }
    }

    if (maxi == 0)
    return maxi1;

    return maxi;
}