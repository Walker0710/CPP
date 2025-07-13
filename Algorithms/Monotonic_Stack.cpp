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