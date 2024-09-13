#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

// only rec
int solve(int m, int n, int maxMove, int startRow, int startColumn)
{

    if (maxMove < 0)
        return 0;

    if ((startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) && maxMove >= 0)
        return 1;

    int ans = 0;

    // right
    ans = ans + solve(m, n, maxMove - 1, startRow, startColumn + 1);

    // left
    ans = ans + solve(m, n, maxMove - 1, startRow, startColumn - 1);

    // up
    ans = ans + solve(m, n, maxMove - 1, startRow - 1, startColumn);

    // down
    ans = ans + solve(m, n, maxMove - 1, startRow + 1, startColumn);

    return (ans) % (100000007);
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{

    return solve(m, n, maxMove, startRow, startColumn);
}

// rec + mem
int solveMem(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp)
{

    if (maxMove < 0)
        return 0;

    if ((startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) && maxMove >= 0)
        return 1;

    if (dp[maxMove][startRow][startColumn] != -1)
        return dp[maxMove][startRow][startColumn];

    int ans = 0;

    // right
    ans = ans + solveMem(m, n, maxMove - 1, startRow, startColumn + 1, dp);

    // left
    ans = ans + solveMem(m, n, maxMove - 1, startRow, startColumn - 1, dp);

    // up
    ans = ans + solveMem(m, n, maxMove - 1, startRow - 1, startColumn, dp);

    // down
    ans = ans + solveMem(m, n, maxMove - 1, startRow + 1, startColumn, dp);

    return dp[maxMove][startRow][startColumn] = (ans) % (100000007);
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return solveMem(m, n, maxMove, startRow, startColumn, dp);
}

// solution from leetcode

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    memo = vector<vector<vector<long>>>(m + 1, vector<vector<long>>(n + 1, vector<long>(maxMove + 1, -1)));
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            fill(memo[i][j].begin(), memo[i][j].end(), -1);
        }
    }
    return static_cast<int>(helper(m, n, maxMove, startRow, startColumn));
}

vector<vector<vector<long>>> memo;
const int mod = 1000000007;

long helper(int m, int n, int maxMove, int row, int col)
{
    if (maxMove < 0)
    {
        return 0;
    }

    // Boundary Condition
    if (row == m || col == n || row < 0 || col < 0)
    {
        return 1;
    }

    if (memo[row][col][maxMove] != -1)
    {
        return memo[row][col][maxMove];
    }

    long total = 0;
    long left = helper(m, n, maxMove - 1, row, col - 1);
    long right = helper(m, n, maxMove - 1, row, col + 1);
    long up = helper(m, n, maxMove - 1, row - 1, col);
    long down = helper(m, n, maxMove - 1, row + 1, col);

    total = ((left + right + up + down) % mod);
    memo[row][col][maxMove] = total;
    return total;
}

