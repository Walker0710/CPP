#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only rec
int solve(vector<vector<int>> &grid, int i, int j)
{

    int row = grid.size();
    int col = grid[0].size();

    if (i == row - 1 && j == col - 1)
        return grid[i][j];

    if (i >= row || j >= col)
        return INT_MAX - 300;

    int right = grid[i][j] + solve(grid, i, j + 1);
    int down = grid[i][j] + solve(grid, i + 1, j);

    return min(right, down);
}

int minPathSum(vector<vector<int>> &grid)
{
    return solve(grid, 0, 0);
}

// rec + mem
int solveMem(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    int row = grid.size();
    int col = grid[0].size();

    if (i == row - 1 && j == col - 1)
        return grid[i][j];

    if (i >= row || j >= col)
        return INT_MAX - 300;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = grid[i][j] + solveMem(grid, i, j + 1, dp);
    int down = grid[i][j] + solveMem(grid, i + 1, j, dp);

    return dp[i][j] = min(right, down);
}

int minPathSum(vector<vector<int>> &grid)
{

    vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
    return solveMem(grid, 0, 0, dp);
}

// Tabulation
int solveTab(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    dp[row-1][col-1] = grid[row - 1][col - 1];

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            if(i == row - 1 && j == col -1)
            continue;

            int right = INT_MAX;
            if(j+1 < col && j+1 >= 0)
            right = grid[i][j] + dp[i][j+1];

            int down = INT_MAX;
            if(i+1 >= 0 && i+1 < row)
            down = grid[i][j] + dp[i+1][j];

            dp[i][j] = min(right, down);
        }
    }
    return dp[0][0];
}

int minPathSum(vector<vector<int>> &grid)
{
    return solveTab(grid);
}
