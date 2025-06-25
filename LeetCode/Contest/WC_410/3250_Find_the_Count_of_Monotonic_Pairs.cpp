#include <bits/stdc++.h>

using namespace std;

// << ,
int mod = 1e9 + 7;

int solve(int index, vector<int> &nums, int prev1, int prev2, vector<vector<vector<int>>> &dp)
{
    if (index == nums.size())
        return 1;

    if (dp[index][prev1][prev2] != -1)
        return dp[index][prev1][prev2];

    int ans = 0;

    for (int i = prev1; i < nums[index]; i++)
    {
        int one = i;
        int two = nums[index] - i;

        if (one >= prev1 && two <= prev2)
        {
            ans = (ans + solve(index + 1, nums, one, two, dp)) % mod;
        }
    }

    return dp[index][prev1][prev2] = ans;
}

int countOfPairs(vector<int> &nums)
{
    vector<vector<vector<int>>> dp(nums.size() + 1, vector<vector<int>>(52, vector<int>(52, -1)));

    return solve(0, nums, 0, 50, dp);
}

int mod = 1e9 + 7;
int dp[2001][52][52];

int solve(int i, int n, vector<int> &v, int prev1, int prev2)
{
    if (i == n)
    return 1;
    
    if (dp[i][prev1][prev2] != -1)
    return dp[i][prev1][prev2];

    int ans = 0;

    for (int j = prev1; j <= v[i]; j++)
    {
        int x1 = j;
        int x2 = v[i] - j;
        
        if (x1 >= prev1 && x2 <= prev2)
        {
            ans = (ans + solve(i + 1, n, v, x1, x2)) % mod;
        }
    }

    return dp[i][prev1][prev2] = ans;
}

int countOfPairs(vector<int> &v)
{
    int n = v.size();
    memset(dp, -1, sizeof(dp));

    int ans = solve(0, n, v, 0, 50);
    return ans;
}