#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> nextSmallerElement(vector<int> &arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while (s.top() >= curr)
        {

            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

vector<int> nextGreaterElementIndex(vector<int> &arr, int n)
{

    stack<int> s; 
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && arr[s.top()] < arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top(); 
        }

        s.push(i);
    }

    return ans;
}

int maximumPossibleSize(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    int prev = -1;
    vector<int> next = nextGreaterElementIndex(nums, n);
    int i = 0;

    while (i < n)
    {
        if (i == n - 1 || nums[i] <= nums[i + 1])
        {
            if (nums[i] >= prev)
            {
                prev = nums[i];
                ans++;
            }
            i++;
        }

        else
        {
            if (nums[i] >= prev)
            {
                ans++;
                prev = nums[i];
            }

            i = next[i];  
            
            if (i == -1)
            break;
        }
    }

    return ans;
}
