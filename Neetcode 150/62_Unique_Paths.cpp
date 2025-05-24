#include <bits/stdc++.h>

using namespace std;

// << ,

// rec only

vector<pair<int, int>> direction = {{1, 0}, {0, 1}};

int solve(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    if (i >= m || j >= n)
        return 0;

    int ans = 0;

    for (auto &[dx, dy] : direction)
    {
        int row = i + dx;
        int col = j + dy;

        ans = ans + solve(row, col, m, n);
    }

    return ans;
}

int uniquePaths(int m, int n)
{
    return solve(0, 0, m, n);
}

// rec + memo

vector<pair<int, int>> direction = {{1, 0}, {0, 1}};

int solveMem(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    if (i >= m || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    for (auto &[dx, dy] : direction)
    {
        int row = i + dx;
        int col = j + dy;

        ans = ans + solveMem(row, col, m, n, dp);
    }

    return dp[i][j] = ans;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solveMem(0, 0, m, n, dp);
}

// tabulation

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = 1;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i + 1 < m)
                dp[i][j] += dp[i + 1][j];
            if (j + 1 < n)
                dp[i][j] += dp[i][j + 1];
        }
    }

    return dp[0][0];
}
