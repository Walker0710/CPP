#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = matrix;

    vector<int> maxii(m);

    for (int i = 0; i < m; i++)
    {
        int maxi = 0;

        for (int j = 0; j < n; j++)
        {
            maxi = max(maxi, matrix[j][i]);
        }

        maxii[i] = maxi;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                ans[i][j] = maxii[j];
            }
        }
    }

    return ans;
}