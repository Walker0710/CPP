#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumArea(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int minRow = n;
    int maxRow = 0;

    int minCol = m;
    int maxCol = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);

                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    return (maxRow - minRow + 1)*(maxCol - minCol + 1);
}