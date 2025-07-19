#include <bits/stdc++.h>

using namespace std;

// << ,

bool solve(int mask, int currSum, int k, vector<int> &nums, int n, int target, vector<int> &dp)
{
    if (k == 0 && mask == (1 << n) - 1)
    {
        return true;
    }

    if (dp[mask] != -1)
    {
        return dp[mask];
    }

    if (currSum == target)
    {
        return dp[mask] = solve(mask, 0, k - 1, nums, n, target, dp);
    }

    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)) && currSum + nums[i] <= target)
        {
            if (solve(mask | (1 << i), currSum + nums[i], k, nums, n, target, dp))
            {
                return dp[mask | (1 << i)] = true;
            }
        }
    }

    return dp[mask] = false;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % k != 0)
        return false;

    int target = sum / k;
    int n = nums.size();

    vector<int> dp(1 << n, -1);

    return solve(0, 0, k, nums, n, target, dp);
}