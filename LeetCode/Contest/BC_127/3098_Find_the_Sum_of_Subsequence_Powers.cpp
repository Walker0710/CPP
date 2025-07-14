#include <bits/stdc++.h>

using namespace std;

// << ,

const int MOD = 1e9 + 7;
int dp[51][53][51];

int solve(int ind, int prev, vector<int> &nums, int k, int mini)
{
    if (ind == nums.size())
        return (k == 0) ? mini : 0;

    if (dp[ind][prev + 1][k] != -1)
        return dp[ind][prev + 1][k];

    int inc = 0, exc = 0;

    if (k > 0)
    {
        if (prev == -1)
            inc = solve(ind + 1, ind, nums, k - 1, mini);

        else
            inc = solve(ind + 1, ind, nums, k - 1, min(mini, abs(nums[ind] - nums[prev])));
    }

    exc = solve(ind + 1, prev, nums, k, mini);

    int ans = (inc + exc) % MOD;

    return dp[ind][prev + 1][k] = ans;
}

int sumOfPowers(vector<int> &nums, int k)
{
    memset(dp, -1, sizeof(dp));
    sort(nums.begin(), nums.end());
    return solve(0, -1, nums, k, INT_MAX);
}


int n, mod = 1e9 + 7;
unordered_map<long long, int> dp;

int sim(int i, int prev, int k, int mini, vector<int> &nums)
{
    if (!k)
    return mini;
    
    if (i == n and k)
    return 0;

    long long key = i + 1e2 * prev + 1e4 * k + 1e6 * mini;

    if (dp.find(key) != dp.end())
    return dp[key];

    int skip = sim(i + 1, prev, k, mini, nums);
    int pick = sim(i + 1, i, k - 1, min(mini, prev == -1 ? mod : nums[i] - nums[prev]), nums);

    return dp[key] = (pick + skip) % mod;
}

int sumOfPowers(vector<int> &nums, int k)
{
    n = nums.size();
    sort(nums.begin(), nums.end());

    return sim(0, -1, k, 1e9, nums);
}