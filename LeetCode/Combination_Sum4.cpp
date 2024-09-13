#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
int solve(vector<int> &nums, int target)
{

    if (target == 0)
        return 1;

    if (target < 0)
        return 0;

    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        ans = ans + solve(nums, target - nums[i]);
    }

    return ans;
}

int combinationSum4(vector<int> &nums, int target)
{

    return solve(nums, target);
}

// rec + mem
int solveMem(vector<int> &nums, int target, vector<int> &dp)
{

    if (target == 0)
        return 1;

    if (target < 0)
        return 0;

    if (dp[target] != -1)
        return dp[target];

    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        ans = ans + solveMem(nums, target - nums[i], dp);
    }

    return dp[target] = ans;
}

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, -1);
    return solveMem(nums, target, dp);
}

// Tabulation
int solveTab(vector<int> &nums, int n)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int target = 1; target <= n; target++)
    {

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(target - nums[i] >= 0)
            ans = ans + dp[target - nums[i]];
        }

        dp[target] = ans;
    }
    return dp[n];
}

int combinationSum4(vector<int> &nums, int n)
{
    return solveTab(nums, n);
}
