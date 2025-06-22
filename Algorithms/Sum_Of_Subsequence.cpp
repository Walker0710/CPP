#include <bits/stdc++.h>

using namespace std;

// << ,

const int MOD = 1e9 + 7;

long long solve(int index, int prev, vector<int> &nums, vector<vector<long long>> &dp)
{
    if (index == nums.size())
        return 0;

    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    long long res = solve(index + 1, prev, nums, dp);

    if (prev == -1 || abs(nums[index] - nums[prev]) == 1)
    {
        long long include_sum = (nums[index] + solve(index + 1, index, nums, dp)) % MOD;
        res = (res + include_sum) % MOD;
    }

    dp[index][prev + 1] = res;

    return res;
}

int sumOfGoodSubsequences(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 2, -1));

    long long total = solve(0, -1, nums, dp) % MOD;

    return total;
}

int sumOfGoodSubsequences(vector<int> &nums)
{
    const int MOD = 1e9 + 7;

    unordered_map<int, pair<long long, long long>> rec;

    long long ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int val = nums[i];
        long long sum = 0;
        long long count = 0;

        if (rec.count(val - 1))
        {
            auto &oneLess = rec[val - 1];
            sum = (sum + oneLess.first + 1LL * oneLess.second * val % MOD) % MOD;
            count = (count + oneLess.second) % MOD;
        }

        if (rec.count(val + 1))
        {
            auto &oneMore = rec[val + 1];
            sum = (sum + oneMore.first + 1LL * oneMore.second * val % MOD) % MOD;
            count = (count + oneMore.second) % MOD;
        }

        sum = (sum + val) % MOD;

        rec[val].first = (rec[val].first + sum) % MOD;
        rec[val].second = (rec[val].second + count + 1) % MOD;

        ans = (ans + sum) % MOD;
    }

    return ans;
}