#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int n, vector<int> &nums, unordered_map<int, int> &m, vector<int> &dp)
{
    if (i == n)
    return 0;
    
    if (dp[i] != -1)
    return dp[i];

    int exc = 0 + solve(i + 1, n, nums, m, dp);
    
    int inc = m[nums[i]] * nums[i];

    if (i + 1 < n && nums[i] + 1 == nums[i + 1])
    inc += solve(i + 2, n, nums, m, dp);
    
    else if (i + 1 < n && nums[i] + 1 != nums[i + 1])
    inc += solve(i + 1, n, nums, m, dp);

    return dp[i] = max(inc, exc);
}

int deleteAndEarn(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (int i : nums)
    m[i]++;

    vector<int> v;

    for (auto i : m)
    v.push_back(i.first);
    
    sort(v.begin(), v.end());
    int n = v.size();
    
    vector<int> dp(n, -1);

    return solve(0, n, v, m, dp);
}