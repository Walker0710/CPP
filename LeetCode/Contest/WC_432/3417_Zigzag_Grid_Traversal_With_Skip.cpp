#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> zigzagTraversal(vector<vector<int>> &grid)
{
    vector<int> ans;
    int n = grid.size();
    int m = grid[0].size();

    bool pick = true;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (pick)
                    ans.push_back(grid[i][j]);
                pick = !pick;
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (pick)
                    ans.push_back(grid[i][j]);
                pick = !pick;
            }
        }
    }

    return ans;
}
