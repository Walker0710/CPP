#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

bool isMonochrome(vector<vector<int>> &matrix, int i, int j, int h, int w)
{
    int color = matrix[i][j];
    for (int r = i; r < i + h; r++)
    {
        for (int c = j; c < j + w; c++)
        {
            if (matrix[r][c] != color)
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
        minCut = min(minCut, 1 + minCuts(matrix, i, j, r, w, dp) + minCuts(matrix, i + r, j, h - r, w, dp));
    }

    // Try all vertical cuts
    for (int c = 1; c < w; c++)
    {
        minCut = min(minCut, 1 + minCuts(matrix, i, j, h, c, dp) + minCuts(matrix, i, j + c, h, w - c, dp));
    }

    return dp[i][j][h][w] = minCut;
}

int getMinimumCuts(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Initialize 4D dp array with -1
    vector<vector<vector<vector<int>>>> dp(m + 1, 
        vector<vector<vector<int>>>(n + 1, 
            vector<vector<int>>(m + 1, 
                vector<int>(n + 1, -1))));
    
    return minCuts(matrix, 0, 0, m, n, dp);
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    cout << getMinimumCuts(matrix) << endl;
    return 0;
}