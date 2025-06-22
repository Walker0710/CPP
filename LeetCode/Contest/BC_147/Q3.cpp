#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int j, int k, vector<int> &nums, vector<vector<vector<int>>> &dp)
{
    if (k >= nums.size())
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int exc = solve(i, j, k + 1, nums, dp);
    int inc = INT_MIN;

    if (abs(nums[i] - nums[j]) >= abs(nums[j] - nums[k]))
    {
        inc = 1 + solve(j, k, k + 1, nums, dp);
    }

    return dp[i][j][k] = max(inc, exc);
}

int longestSubsequence(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    if (nums.size() <= 2)
        return nums.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + solve(i, j, j + 1, nums, dp));
        }
    }

    return ans;
}



int longestSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(301, vector<int>(301, 0));
    int maxLength = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int current = nums[i];
       
        for (int next = 1; next <= 300; next++)
        {
            int difference = abs(current - next);
            dp[current][difference] = max(dp[current][difference], dp[next][difference] + 1);
        }
       
        for (int diff = 1; diff <= 300; diff++)
        {
            dp[current][diff] = max(dp[current][diff], dp[current][diff - 1]);
        }
        maxLength = max(maxLength, dp[current][300]);
    }

    return maxLength;
}