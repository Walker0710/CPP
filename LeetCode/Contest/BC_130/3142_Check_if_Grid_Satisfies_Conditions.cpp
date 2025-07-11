#include <bits/stdc++.h>

using namespace std;

// << ,

bool satisfiesConditions(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    for (int j = 1; j < m; ++j)
    {
        if (grid[0][j - 1] == grid[0][j])
        return false;
    }

    for (int j = 0; j < m; ++j)
    {
        for (int i = 1; i < n; ++i)
        {
            if (grid[i][j] != grid[0][j])
            return false;
        }
    }

    return true;
}