#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int rem, vector<vector<int>> &dp, vector<int> &nums, int k)
{
    if (dp[i][rem] != 0)
    {
        return dp[i][rem];
    }

    int res = 1;

    for (int j = i + 1; j < nums.size(); j++)
    {
        if ((nums[j] + nums[i]) % k == rem)
        {
            res += solve(j, rem, dp, nums, k);
            break;
        }
    }

    dp[i][rem] = res;
    return res;
}

int maximumLength(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k, 0));

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int len = 1 + solve(j, (nums[i] + nums[j]) % k, dp, nums, k);

            if (len > res)
            {
                res = len;
            }
        }
    }

    return res;
}
