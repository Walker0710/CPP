#include <bits/stdc++.h>

using namespace std;

// << ,

int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
{
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int j = 0; j < m; ++j)
    {
        dp[0][j] = grid[0][j];
        pq.push({dp[0][j], {0, j}});
    }

    while (!pq.empty())
    {
        auto [cost, pos] = pq.top();
        pq.pop();

        int row = pos.first;
        int col = pos.second;

        if (cost > dp[row][col])
        continue;

        if (row == n - 1)
        continue;

        for (int i = 0; i < m; ++i)
        {
            int nextRow = row + 1;
            int moveC = moveCost[grid[row][col]][i];
            int newCost = cost + moveC + grid[nextRow][i];

            if (newCost < dp[nextRow][i])
            {
                dp[nextRow][i] = newCost;
                pq.push({newCost, {nextRow, i}});
            }
        }
    }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}