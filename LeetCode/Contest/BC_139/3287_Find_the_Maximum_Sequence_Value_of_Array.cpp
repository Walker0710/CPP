#include <bits/stdc++.h>

using namespace std;

// << ,

bool solve(int i, int len, int aur, vector<int> &nums, int k, vector<vector<vector<int>>> &dp)
{
    if (i >= nums.size())
    return len == k;

    if (dp[i][len][aur] != -1)
    return dp[i][len][aur];

    bool take = 0;
    bool notake = 0;
    
    if (len < k)
    take = solve(i + 1, len + 1, aur | nums[i], nums, k, dp);
    
    notake = solve(i + 1, len, aur, nums, k, dp);
    
    return dp[i][len][aur] = take || notake;
}

int maxValue(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp1(n + 1, vector<vector<int>>(k + 1, vector<int>(129, -1)));
    vector<vector<vector<int>>> dp2(n + 1, vector<vector<int>>(k + 1, vector<int>(129, -1)));

    solve(0, 0, 0, nums, k, dp1);

    reverse(nums.begin(), nums.end());
    solve(0, 0, 0, nums, k, dp2);

    int ans = 0;

    for (int i = k; i <= n - k; i++)
    {
        for (int or1 = 0; or1 < 128; or1++)
        {
            for (int or2 = 0; or2 < 128; or2++)
            {
                if (dp1[i][k][or1] == -1 || dp2[n - i][k][or2] == -1)
                    continue;
                if (dp1[i][k][or1] && dp2[n - i][k][or2])
                    ans = max(ans, or1 ^ or2);
            }
        }
    }

    return ans;
}