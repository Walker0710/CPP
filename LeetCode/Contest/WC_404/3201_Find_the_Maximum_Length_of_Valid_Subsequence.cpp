#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[200001][200001][2];

int solve(int i, int prevIdx, int rem, vector<int> &nums)
{
    if (i == nums.size())
        return 0;

    if (dp[i][prevIdx + 1][rem] != -1)
        return dp[i][prevIdx + 1][rem];

    int take = 0;
    int notTake = solve(i + 1, prevIdx, rem, nums);

    if (prevIdx == -1 || (nums[i] + nums[prevIdx]) % 2 == rem)
    {
        take = 1 + solve(i + 1, i, rem, nums);
    }

    return dp[i][prevIdx + 1][rem] = max(take, notTake);
}

int maximumLength(vector<int> &nums)
{
    int n = nums.size();
    memset(dp, -1, sizeof(dp));

    int evenRem = solve(0, -1, 0, nums);
    memset(dp, -1, sizeof(dp));
    int oddRem = solve(0, -1, 1, nums);

    return max(evenRem, oddRem);
}





int memo[200001][3];

int solve(vector<int> &nums, int index, bool lastEven)
{
    if (index == nums.size())
    return 0;

    if (memo[index][lastEven] != -1)
    return memo[index][lastEven];

    int skip = solve(nums, index + 1, lastEven);
    int pick = 0;

    if ((nums[index] % 2 == 0 && !lastEven) || (nums[index] % 2 != 0 && lastEven))
    {
        pick = 1 + solve(nums, index + 1, nums[index] % 2 == 0);
    }

    return memo[index][lastEven] = max(skip, pick);
}
int maximumLength(vector<int> &nums)
{
    int n = nums.size();
    memset(memo, -1, sizeof(memo));
 
    int y = max(solve(nums, 0, true), solve(nums, 0, false));
    int ct = 0;
    int ct1 = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            ct++;
        }
        else
        {
            ct1++;
        }
    }
 
    int u = max(ct, ct1);
    int ans = max(u, y);
    return ans;
}