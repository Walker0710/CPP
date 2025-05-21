#include <bits/stdc++.h>

using namespace std;

// << ,

vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isCheck(vector<vector<int>> &grid, int k, int i, int j, vector<vector<bool>> &visited)
{
    int n = grid.size();

    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || grid[i][j] > k)
    return false;

    if (i == n - 1 && j == n - 1)
    return true;

    visited[i][j] = true;

    for (auto &[dx, dy] : direction)
    {
        int row = i + dx;
        int col = j + dy;

        if (isCheck(grid, k, row, col, visited))
        {
            return true;
        }
    }

    return false;
}

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    int s = grid[0][0], e = n * n - 1;
    int ans = e;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        if (isCheck(grid, mid, 0, 0, visited))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}