#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumOperations(vector<vector<int>> &grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        int prev = grid[0][i];

        for (int j = 1; j < n; j++)
        {
            if (grid[j][i] <= prev)
            {
                ans += prev + 1 - grid[j][i];
                prev = prev + 1;
            }
            
            else
            {
                prev = grid[j][i];
            }
        }
    }

    return ans;
}
