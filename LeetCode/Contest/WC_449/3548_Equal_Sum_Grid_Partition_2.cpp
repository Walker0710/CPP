#include <bits/stdc++.h>

using namespace std;

// << ,

bool canPartitionGrid(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    unordered_map<long, set<int>> rowMap, colMap;

    vector<long> rowSums(m, 0), colSums(n, 0);
    vector<long> rowPrefix(m, 0), colPrefix(n, 0);

    // compute row sums, column sums and fill rowMap
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            long val = grid[i][j];
            rowMap[val].insert(i);
            rowSums[i] += val;
            colSums[j] += val;
        }
    }

    // fill colMap
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            long val = grid[i][j];
            colMap[val].insert(j);
        }
    }

    // compute prefix sums
    rowPrefix[0] = rowSums[0];
    colPrefix[0] = colSums[0];
    
    for (int i = 1; i < m; ++i)
        rowPrefix[i] = rowPrefix[i - 1] + rowSums[i];
    
    for (int j = 1; j < n; ++j)
        colPrefix[j] = colPrefix[j - 1] + colSums[j];

    // try vertical partitions
    for (int j = 1; j < n; ++j)
    {
        long left = colPrefix[j - 1];
        long right = colPrefix[n - 1] - left;
        
        if (left == right)
            return true;

        long diff = abs(left - right);
        
        if (left > right)
        {
            if (j == 1)
            {
                if (grid[0][0] == diff || grid[m - 1][0] == diff)
                    return true;
            }
        
            else if (colMap.count(diff))
            {
                auto it = colMap[diff].lower_bound(j);
                if (it != colMap[diff].begin())
                {
                    --it;
                    int pos = *it;
                    if (pos == j - 1 || pos == 0 || m != 1)
                        return true;
                }
            }
        }
        
        else
        {
            if (j == n - 1)
            {
                if (grid[0][j] == diff || grid[m - 1][j] == diff)
                    return true;
            }
            else if (colMap.count(diff))
            {
                auto it = colMap[diff].upper_bound(j - 1);
                if (it != colMap[diff].end())
                {
                    int pos = *it;
                    if (pos == j || pos == n - 1 || m != 1)
                        return true;
                }
            }
        }
    }

    // try horizontal partitions
    for (int i = 1; i < m; ++i)
    {
        long top = rowPrefix[i - 1];
        long bottom = rowPrefix[m - 1] - top;
        if (top == bottom)
            return true;

        long diff = abs(top - bottom);

        if (top > bottom)
        {
            if (i == 1)
            {
                if (grid[0][0] == diff || grid[0][n - 1] == diff)
                    return true;
            }

            else if (rowMap.count(diff))
            {
                auto it = rowMap[diff].lower_bound(i);
                if (it != rowMap[diff].begin())
                {
                    --it;
                    int pos = *it;
                    if (pos == i - 1 || pos == 0 || n != 1)
                        return true;
                }
            }
        }

        else
        {
            if (i == m - 1)
            {
                if (grid[i][0] == diff || grid[i][n - 1] == diff)
                    return true;
            }

            else if (rowMap.count(diff))
            {
                auto it = rowMap[diff].upper_bound(i - 1);

                if (it != rowMap[diff].end())
                {
                    int pos = *it;
                    if (pos == i || pos == m - 1 || n != 1)
                        return true;
                }
            }
        }
    }

    return false;
}