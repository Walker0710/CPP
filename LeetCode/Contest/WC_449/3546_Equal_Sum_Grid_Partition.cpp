#include <bits/stdc++.h>

using namespace std;

// << ,

bool canPartitionGrid(vector<vector<int>> &grid)
{
    long long n = grid.size();
    long long m = grid[0].size();

    long long total = 0;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            total += grid[i][j];
        }
    }

    if (total % 2)
        return false;

    total /= 2;
    long long prev = 0;

    // Row-wise partition
    for (long long i = 0; i < n; i++)
    {
        prev += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        if (prev == total)
            return true;
    }

    // Transpose grid for column-wise partition check
    vector<vector<long long>> tras(m, vector<long long>(n, 0)); // ✅ fixed

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            tras[j][i] = grid[i][j]; // ✅ fixed
        }
    }

    prev = 0;

    // Column-wise partition
    for (long long i = 0; i < m; i++)
    {
        prev += accumulate(tras[i].begin(), tras[i].end(), 0LL);
        if (prev == total)
            return true;
    }

    return false;
}
