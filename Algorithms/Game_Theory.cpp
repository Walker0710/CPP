#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
    return 0;

    if (dp[i][j] != -1)
    return dp[i][j];

    int first = nums[i] + min(solve(nums, i + 2, j, dp), solve(nums, i + 1, j - 1, dp));
    int last = nums[j] + min(solve(nums, i + 1, j - 1, dp), solve(nums, i, j - 2, dp));

    return dp[i][j] = max(first, last);
}

bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    int val = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int res1 = solve(nums, 0, nums.size() - 1, dp);
    int res2 = val - res1;

    return res1 >= res2;
}


int solve(vector<int> &nums, int i, int j, int chance)
{
    if (i > j)
    return 0;

    if (chance == 0)
    return max(nums[i] + solve(nums, i + 1, j, 1), nums[j] + solve(nums, i, j - 1, 1));
    
    else
    return min(solve(nums, i + 1, j, 0), solve(nums, i, j - 1, 0));
}

bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    long long sum = 0;

    for (int i = 0; i < n; i++)
    sum = sum + nums[i];

    long long one = (long long)solve(nums, 0, n - 1, 0);
    
    sum = sum - one;
    return (one >= sum);
}