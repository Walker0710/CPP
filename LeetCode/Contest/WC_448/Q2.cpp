#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(vector<vector<int>> &ans, int row, int col, int size, int &cnt)
{
    if (size == 1)
    {
        ans[row][col] = cnt;
        cnt++;
        return;
    }

    solve(ans, row, col + size / 2, size / 2, cnt);
    solve(ans, row + size / 2, col + size / 2, size / 2, cnt);
    solve(ans, row + size / 2, col, size / 2, cnt);
    solve(ans, row, col, size / 2, cnt);
}

vector<vector<int>> specialGrid(int n)
{
    int size = pow(2, n);
    vector<vector<int>> ans(size, vector<int>(size, 0));
    int cnt = 0;

    solve(ans, 0, 0, size, cnt);

    return ans;
}