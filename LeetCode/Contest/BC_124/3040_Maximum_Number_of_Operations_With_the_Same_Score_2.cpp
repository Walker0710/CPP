#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[2001][2001];

int solve(int l, int r, vector<int> &nums, int sum)
{

    if (r - l + 1 < 2)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int one = 0;
    int two = 0;
    int three = 0;

    if (l + 1 <= r && nums[l] + nums[l + 1] == sum)
    {
        one = 1 + solve(l + 2, r, nums, sum);
    }

    if (r - 1 >= l && nums[r - 1] + nums[r] == sum)
    {
        two = 1 + solve(l, r - 2, nums, sum);
    }

    if (l < r && nums[l] + nums[r] == sum)
    {
        three = 1 + solve(l + 1, r - 1, nums, sum);
    }

    return dp[l][r] = max({one, two, three});
}

int maxOperations(vector<int> &nums)
{
    int n = nums.size();

    memset(dp, -1, sizeof(dp));
    int first = solve(0, n - 1, nums, nums[0] + nums[1]);

    memset(dp, -1, sizeof(dp));
    int second = solve(0, n - 1, nums, nums[n - 2] + nums[n - 1]);

    memset(dp, -1, sizeof(dp));
    int third = solve(0, n - 1, nums, nums[0] + nums[n - 1]);

    return max({first, second, third});
}