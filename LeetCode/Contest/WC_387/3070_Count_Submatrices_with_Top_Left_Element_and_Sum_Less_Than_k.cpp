#include <bits/stdc++.h>

using namespace std;

// << ,

int countSubmatrices(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] += grid[i - 1][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < m; j++)
        {
            sum += grid[i][j];

            if (sum > k)
            break;

            cnt++;
        }
    }

    return cnt;
}