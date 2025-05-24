#include <bits/stdc++.h>

using namespace std;

// << ,

// rec only
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


// rec + memo
int solve(vector<int> &nums, int target, int index, map<pair<int, int>, int> &dp)
{
    if (index == nums.size())
        return target == 0 ? 1 : 0;

    pair<int, int> key = {index, target};

    if (dp.count(key))
        return dp[key];

    // assigning +
    int plus = solve(nums, target - nums[index], index + 1, dp);

    // assigning -
    int negative = solve(nums, target + nums[index], index + 1, dp);

    return dp[key] = plus + negative;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    map<pair<int, int>, int> dp;
    return solve(nums, target, 0, dp);
}


// tabulation
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n+1);
    dp[n][0] = 1;

    for(int index = n-1; index>=0; index--) {
        for(int tar = 0; tar <= target; tar++) {

            int plus = dp[index + 1][tar - nums[index]];
            int neg = dp[index + 1][tar + nums[index]];

            dp[index][tar] = plus + neg;
        }
    }

    return dp[0][target];
}


