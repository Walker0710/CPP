#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

bool isMonochrome(vector<vector<int>> &matrix, int i, int j, int h, int w)
{
    int color = grid[i][j];
    for (int r = i; r < i + h; r++)
    {
        for (int c = j; c < j + w; c++)
        {
            if (grid[r][c] != color)
            return false;
        }
    }
    return true;
}

int minCuts(vector<vector<int>> &matrix ,int i, int j, int h, int w, vector<vector<vector<vector<int>>>> &dp)
{

    if (dp[i][j][h][w] != -1)
        return dp[i][j][h][w];

    if (isMonochrome(matrix, i, j, h, w))
        return dp[i][j][h][w] = 0;

    int minCut = INT_MAX;

    // Try all horizontal cuts
    for (int r = 1; r < h; r++)
    {
        minCut = min(minCut, 1 + minCuts(i, j, r, w) + minCuts(i + r, j, h - r, w));
    }

    // Try all vertical cuts
    for (int c = 1; c < w; c++)
    {
        minCut = min(minCut, 1 + minCuts(i, j, h, c) + minCuts(i, j + c, h, w - c));
    }

    return dp[i][j][h][w] = minCut;
}

int getMinimumCuts(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<vector<vector<int>>>> dp;
    return minCuts(matrix ,0, 0, m, n, dp);
}
