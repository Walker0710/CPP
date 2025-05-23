#include <bits/stdc++.h>

using namespace std;

// << ,

// rec + memo
bool solveOptRec(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
{
    if (index >= nums.size())
        return false;

    if (target == 0)
        return true;

    if (target < 0)
        return false;

    if (dp[index][target] != -1)
        return dp[index][target];

    // inc
    bool first = solveOptRec(nums, index + 1, target - nums[index], dp);

    // exc
    bool second = solveOptRec(nums, index + 1, target, dp);

    return dp[index][target] = (first || second);
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totSum = 0;

    for (int i = 0; i < n; i++)
        totSum += nums[i];

    if (totSum % 2)
        return false;

    int target = totSum / 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return solveOptRec(nums, 0, target, dp);
}

// tabulation
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totSum = 0;

    for (int i = 0; i < n; i++)
        totSum += nums[i];

    if (totSum % 2)
        return false;

    int target = totSum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1; 

    for (int index = n - 1; index >= 0; index--)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            bool first = false;
            if (tar >= nums[index])
                first = dp[index + 1][tar - nums[index]];

            bool second = dp[index + 1][tar];

            dp[index][tar] = (first || second);
        }
    }

    return dp[0][target];
}