#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int j, int k, vector<int> &nums, vector<vector<vector<int>>> &dp)
{
    if (i >= nums.size() && j >= nums.size() && k >= nums.size())
    {
        return 0;
    }

    if (j >= nums.size() && k >= nums.size())
    {
        return nums[i];
    }

    if (k >= nums.size())
    {
        return max(nums[i], nums[j]);
    }

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    // i and j
    int one = max(nums[i], nums[j]) + solve(k, k + 1, k + 2, nums, dp);

    // j and k
    int two = max(nums[j], nums[k]) + solve(i, k + 1, k + 2, nums, dp);

    // i and k
    int three = max(nums[i], nums[k]) + solve(j, k + 1, k + 2, nums, dp);

    return dp[i][j][k] = min(one, min(two, three));
}

int minCost(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
    return solve(0, 1, 2, nums, dp);
}



int cal(int ext, int ind, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return nums[ext];

    if (ind == nums.size() - 1)
        return max(nums[ext], nums[ind]);

    if (dp[ind][ext] != -1)
        return dp[ind][ext];

    // Trying all 3 cases of choosing 2 elements
    int f = max(nums[ind], nums[ind + 1]) + cal(ext, ind + 2, nums, dp);
    int s = max(nums[ext], nums[ind + 1]) + cal(ind, ind + 2, nums, dp);
    int t = max(nums[ext], nums[ind]) + cal(ind + 1, ind + 2, nums, dp);

    return dp[ind][ext] = min({f, s, t});
}

int minCost(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return cal(0, 1, nums, dp);
}
