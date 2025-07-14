#include <bits/stdc++.h>

using namespace std;

// << ,

int mod = 1e9 + 7;
int n;
int dp[101][101][101];

int func(int x)
{
    int ans = 1;
    
    while (x--)
    ans = (ans * 2) % mod;
    
    return ans;
}

int helper(int ind, vector<int> &nums, int curr_sum, int count, int k)
{
    if (curr_sum > k)
    return 0;
    
    if (curr_sum == k)
    return func(n - count);

    if (ind == n)
    return 0;
    
    if (dp[ind][curr_sum][count] != -1)
    return dp[ind][curr_sum][count];

    int cnt = 0;

    cnt = (cnt + helper(ind + 1, nums, curr_sum + nums[ind], count + 1, k)) % mod;
    cnt = (cnt + helper(ind + 1, nums, curr_sum, count, k)) % mod;

    return dp[ind][curr_sum][count] = cnt;
}

int sumOfPower(vector<int> &nums, int k)
{
    n = nums.size();
    memset(dp, -1, sizeof(dp));

    return helper(0, nums, 0, 0, k);
}