#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

// only rec
int solve(vector<vector<int>> &matrix, int row, int col)
{

    if (row >= matrix.size())
        return 0;

    int ans = 0;
    int left = INT_MAX - 101;
    int middle = INT_MAX - 101;
    int right = INT_MAX - 101;

    if (col != 0)
        left = matrix[row][col] + solve(matrix, row + 1, col - 1);

    middle = matrix[row][col] + solve(matrix, row + 1, col);

    if (col != matrix.size() - 1)
        right = matrix[row][col] + solve(matrix, row + 1, col + 1);

    ans = min(left, min(middle, right));

    return ans;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int ans = INT_MAX;

    for (int i = 0; i < matrix.size(); i++)
    {
        ans = min(ans, solve(matrix, 0, i));
    }

    return ans;
}

// rec + mem
int solveMem(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
{

    if (row >= matrix.size())
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int ans = 0;
    int left = INT_MAX - 101;
    int middle = INT_MAX - 101;
    int right = INT_MAX - 101;

    if (col != 0)
        left = matrix[row][col] + solveMem(matrix, row + 1, col - 1, dp);

    middle = matrix[row][col] + solveMem(matrix, row + 1, col, dp);

    if (col != matrix.size() - 1)
        right = matrix[row][col] + solveMem(matrix, row + 1, col + 1, dp);

    ans = min(left, min(middle, right));

    return dp[row][col] = ans;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int ans = INT_MAX;
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 1, -1));

    for (int i = 0; i < matrix.size(); i++)
    {
        ans = min(ans, solveMem(matrix, 0, i, dp));
    }

    return ans;
}

// tabuation
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 1, INT_MAX - 101));

    for (int i = 0; i <= n; i++)
        dp[n][i] = 0;

    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = n - 1; col >= 0; col--)
        {
            int left = INT_MAX - 101;
            int middle = INT_MAX - 101;
            int right = INT_MAX - 101;

            if (col != 0)
                left = matrix[row][col] + dp[row + 1][col - 1];

            middle = matrix[row][col] + dp[row + 1][col];

            if (col != n - 1)
                right = matrix[row][col] + dp[row + 1][col + 1];

            dp[row][col] = min(left, min(middle, right));
        }
    }
    int  ans = INT_MAX;
    for(int i = 0; i<n; i++) {
        ans = min(ans, dp[0][i]);
    }
    return ans;
}