#include <bits/stdc++.h>

using namespace std;

// << ,

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