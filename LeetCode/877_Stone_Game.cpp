#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

        return dp[i][j];
    int first = nums[i] + min(solve(nums, i + 2, j, dp), solve(nums, i + 1, j - 1, dp));
    int last = nums[j] + min(solve(nums, i + 1, j - 1, dp), solve(nums, i, j - 2, dp));
    return dp[i][j] = max(first, last);
}

bool stoneGame(vector<int>& nums) {

    int n = nums.size();
    int val = 0;

    for (int i = 0; i < n; i++)
        val = val + nums[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int res1 = solve(nums, 0, nums.size() - 1, dp);
    int res2 = val - res1;
    return res1 >= res2;
}