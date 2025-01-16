#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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


int maxArea(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int area = largestRectangleArea(mat[0]);

    for(int i = 1; i<n; i++) {
        for(int j = 0; j<m; j++) {

            if(mat[i][j] == 1)
            mat[i][j] += mat[i-1][j];

            else 
            mat[i][j] = 0; 
        }

        area = max(area, largestRectangleArea(mat[i]));
    }

    return area;
}
