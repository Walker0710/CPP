#include <bits/stdc++.h>

using namespace std;

// << ,

int findMaxValue(vector<vector<int>> &mat, int n)
{
    vector<vector<int>> maxMat(n, vector<int>(n));

    maxMat[n - 1][n - 1] = mat[n - 1][n - 1];

    for (int j = n - 2; j >= 0; --j)
    maxMat[n - 1][j] = max(mat[n - 1][j], maxMat[n - 1][j + 1]);

    for (int i = n - 2; i >= 0; --i)
    maxMat[i][n - 1] = max(mat[i][n - 1], maxMat[i + 1][n - 1]);

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = n - 2; j >= 0; --j)
        {
            maxMat[i][j] = max({mat[i][j], maxMat[i + 1][j], maxMat[i][j + 1]});
        }
    }

    int ans = INT_MIN;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            ans = max(ans, maxMat[i + 1][j + 1] - mat[i][j]);
        }
    }

    return ans;
}