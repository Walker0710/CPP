#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &height)
{

    int n = height.size();
    vector<int> next(n);
    next = nextSmallerElement(height, n);

    vector<int> prev(n);
    prev = prevSmallerElement(height, n);
    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        int l = height[i];

        if (next[i] == -1)
            next[i] = n;

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}

vector<vector<int>> convertCharMatrixToInt(vector<vector<char>>& mat) {
    
    vector<vector<int>> intMatrix;
    
    for (const auto& row : mat) {
        vector<int> intRow;

        for (char c : row) {
            intRow.push_back(c - '0'); 
        }

        intMatrix.push_back(intRow);
    }
    
    return intMatrix;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> mat = convertCharMatrixToInt(matrix);

    int area = largestRectangleArea(mat[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (mat[i][j] == 1)
                mat[i][j] += mat[i - 1][j];

            else
                mat[i][j] = 0;
        }

        area = max(area, largestRectangleArea(mat[i]));
    }

    return area;
}