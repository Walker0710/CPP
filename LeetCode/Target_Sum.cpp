#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
int solve(vector<int> &nums, int target, int index)
{

    if (target == 0 && index == nums.size())
        return 1;

    if (index >= nums.size())
        return 0;

    // assigning +
    int plus = solve(nums, target - nums[index], index + 1);

    // assigning -
    int negative = solve(nums, target + nums[index], index + 1);

    return plus + negative;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    return solve(nums, target, 0);
}

// rec + mem
int solveMem(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{

    if (target == 0 && index == nums.size())
        return 1;

    if (index >= nums.size())
        return 0;

    if (dp[index][target] != -1)
        return dp[index][target];

    // assigning +
    int plus = solveMem(nums, target - nums[index], index + 1, dp);

    // assigning -
    int negative = solveMem(nums, target + nums[index], index + 1, dp);

    return dp[index][target] = plus + negative;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return solveMem(nums, target, 0, dp);
}

// tabulation
int solveTab(vector<int> &nums, int targetReal)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(targetReal + 1, 0));
    dp[nums.size()][0] = 1;

    for (int index = nums.size() - 1; index >= 0; index++)
    {
        for (int target = 0; target <= targetReal; target++)
        {
            // assigning +
            int plus = dp[index + 1][target - nums[index]];

            // assigning -
            int negative = dp[index + 1][target + nums[index]];

            dp[index][target] = plus + negative;
        }
    }

    return dp[0][targetReal];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    return solveTab(nums, target);
}
