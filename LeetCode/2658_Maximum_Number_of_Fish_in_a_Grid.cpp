#include <bits/stdc++.h>

using namespace std;

// << ,

int dfs(int i, int j, int row, int col, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || j >= col || i >= row || grid[i][j] == 0)
    {
        return 0;
    }

    int ans = grid[i][j];
    grid[i][j] = 0;

    ans += dfs(i - 1, j, row, col, grid);
    ans += dfs(i, j + 1, row, col, grid);
    ans += dfs(i + 1, j, row, col, grid);
    ans += dfs(i, j-1, row, col, grid);

    return ans;
}

int findMaxFish(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    int ans = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] > 0)
            {
                int yoo = dfs(i, j, row, col, grid);

                ans = max(yoo, ans);
            }
        }
    }
    return ans;
}