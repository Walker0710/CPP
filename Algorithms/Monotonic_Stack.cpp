#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> prevGreater(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            result[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    return result;
}

vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--) {

        int curr = arr[i];

        while(s.top() >= curr) {

            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}



vector<int> nextGreater(vector<int> &temperatures)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(temperatures.size(), 0);

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        int curr = temperatures[i];

        while (s.top() != -1 && temperatures[i] >= temperatures[s.top()])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}






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
