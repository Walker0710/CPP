#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int n = nums.size();
    vector<int> pref(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        pref[i + 1] = pref[i] + nums[i];
    }

    int mini = INT_MAX;

    for (int len = l; len <= r; ++len)
    {
        for (int i = 0; i + len <= n; ++i)
        {
            int sum = pref[i + len] - pref[i];
            
            if (sum > 0)
            {
                mini = min(mini, sum);
            }
        }
    }

    return (mini == INT_MAX) ? -1 : mini;
}