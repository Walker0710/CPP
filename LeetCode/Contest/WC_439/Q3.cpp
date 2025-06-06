#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int j, vector<int> &pref, int k, int m)
{
    if (k == 0)
        return 0;

    if (j >= pref.size())
    {
        return INT_MIN;
    }

    // start a new one
    int prevSum = 0;

    if (i == 0)
        prevSum = pref[j];

    else
        prevSum = pref[j] - pref[i - 1];

    int st = INT_MIN;

    if (j - i + 1 >= m)
        st = prevSum + solve(j + 1, j + m, pref, k--, m);

    // extent the current one
    int ext = max(solve(i + 1, j, pref, k, m), solve(i, j + 1, pref, k, m));

    return max(ext, st);
}

int maxSum(vector<int> &nums, int k, int m)
{
    vector<int> pref(nums.size());
    pref[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        pref[i] = nums[i] + pref[i - 1];
    }

    return solve(0, m - 1, pref, k, m);
}

// optimal approch

vector<vector<int>> dp;

int solve(int i, int k, const vector<int> &nums, const vector<int> &pref, int m)
{
    if (k == 0)
        return 0;

    if (i >= nums.size())
        return INT_MIN;

    if (dp[i][k] != -1)
        return dp[i][k];

    int n = nums.size();
    int res = solve(i + 1, k, nums, pref, m); // skip current index

    // Try subarrays starting at i of length m, m+1, ...
    for (int len = m; i + len <= n; ++len)
    {
        int j = i + len - 1;
        int sum = pref[j] - (i > 0 ? pref[i - 1] : 0);
        int next = solve(j + 1, k - 1, nums, pref, m);
        if (next != INT_MIN)
        {
            res = max(res, sum + next);
        }
    }

    return dp[i][k] = res;
}

int maxSum(vector<int> &nums, int k, int m)
{
    int n = nums.size();
    vector<int> pref(n);
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + nums[i];

    dp.assign(n + 1, vector<int>(k + 1, -1));

    return solve(0, k, nums, pref, m);
}

// tabulation

int maxSum(vector<int> &nums, int k, int m)
{
    int n = nums.size();
    vector<int> pref(n);
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + nums[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MIN));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0; // 0 sum for 0 groups

    for (int i = n - 1; i >= 0; i--)
    {
        for (int ki = 1; ki <= k; ki++)
        {
            int res = dp[i + 1][ki]; // skip current index

            for (int len = m; i + len <= n; ++len)
            {
                int j = i + len - 1;
                int sum = pref[j] - (i > 0 ? pref[i - 1] : 0);

                if (dp[j + 1][ki - 1] != INT_MIN)
                {
                    res = max(res, sum + dp[j + 1][ki - 1]);
                }
            }

            dp[i][ki] = res;
        }
    }

    return dp[0][k];
}

int maxSum(vector<int> &nums, int k, int m)
{
    int n = nums.size();
    vector<int> prefix(n + 1, 0);

    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1e9));

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        int best = -1e9;
        for (int j = 0; j <= n; j++)
        {
            if (j > 0)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);

            if (j - m >= 0)
                best = max(best, dp[i][j - m] - prefix[j - m]);

            if (best != -1e9)
                dp[i + 1][j] = max(dp[i + 1][j], prefix[j] + best);
        }
    }

    return dp[k][n];
}