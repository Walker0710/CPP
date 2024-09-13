#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only rec
int solve(vector<vector<int>> &triangle, int row, int col)
{

    if (row == triangle.size())
        return 0;

    int first = solve(triangle, row + 1, col);
    int second = solve(triangle, row + 1, col + 1);

    int ans = triangle[row][col] + min(first, second);

    return ans;
}

int minimumTotal(vector<vector<int>> &triangle)
{

    return solve(triangle, 0, 0);
}

// rec + mem
int solveMem(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> &dp)
{

    if (row == triangle.size())
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int first = solveMem(triangle, row + 1, col, dp);
    int second = solveMem(triangle, row + 1, col + 1, dp);

    int ans = triangle[row][col] + min(first, second);

    return dp[row][col] = ans;
}

int minimumTotal(vector<vector<int>> &triangle)
{

    vector<vector<int>> dp(triangle.size() + 1, vector<int>(triangle.size() + 1, -1));
    return solveMem(triangle, 0, 0, dp);
}

// Tabulation
int solveTab(vector<vector<int>> &triangle)
{

    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int row = n - 1; row >= 0; row--)
    {

        for (int col = row; col >= 0; col--)
        {

            int first = dp[row + 1][col];
            int second = dp[row + 1][col + 1];

            int ans = triangle[row][col] + min(first, second);
            dp[row][col] = ans;
        }
    }

    return dp[0][0];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    return solveTab(triangle);
}