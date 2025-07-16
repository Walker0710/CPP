#include <bits/stdc++.h>

using namespace std;

// << ,

vector<unordered_map<int, int>> dp;

int solve(int ind, vector<int> &nums, int prev)
{
    if (ind == nums.size())
        return 0;

    if (dp[ind].count(prev) != 0)
        return dp[ind][prev];

    int first = 0;
    int second = 0;

    if (nums[ind] == prev + 1 || nums[ind] + 1 == prev + 1)
    {
        first = 1 + solve(ind + 1, nums, prev + 1);
    }

    else
    {
        second = solve(ind + 1, nums, prev);
    }

    return dp[ind][prev] = max(first, second);
}

int maxSelectedElements(vector<int> &nums)
{

    int ans = 0;
    sort(nums.begin(), nums.end());

    dp.resize(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        int one = 1 + solve(i + 1, nums, nums[i]);
        int two = 1 + solve(i + 1, nums, nums[i] + 1);

        ans = max({ans, one, two});
    }

    return ans;
}

vector<int> nums;
int n;
vector<unordered_map<int, int>> memo;

int dp(int i, int prev)
{
    if (i == n)
    {
        return 0;
    }

    if (memo[i].count(prev))
    {
        return memo[i][prev];
    }

    int ans = 0;

    if (nums[i] == prev + 1)
    {
        ans = max(ans, 1 + dp(i + 1, nums[i]));
    }

    if (nums[i] + 1 == prev + 1)
    {
        ans = max(ans, 1 + dp(i + 1, nums[i] + 1));
    }

    // if (nums[i] + 1 == prev)
    // {
    //     ans = max(ans, dp(i + 1, nums[i] + 1));
    // }

    return memo[i][prev] = ans;
}

int maxSelectedElements(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    this->nums = nums;
    this->n = nums.size();
    int ans = 0;
    memo.resize(n);

    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, 1 + dp(i + 1, nums[i]));
        ans = max(ans, 1 + dp(i + 1, nums[i] + 1));
    }

    return ans;
}