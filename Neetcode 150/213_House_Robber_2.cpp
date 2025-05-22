#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(vector<int> &nums, int index, vector<int> &dp) {
    if (index >= nums.size()) {
        return 0;
    }

    if (dp[index] != -1) {
        return dp[index];
    }

    int inc = nums[index] + solve(nums, index + 2, dp);
    int exc = solve(nums, index + 1, dp);

    return dp[index] = max(inc, exc);
}

int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> first(nums.begin(), nums.end() - 1);   // House 0 to n-2
    vector<int> second(nums.begin() + 1, nums.end()); // House 1 to n-1

    vector<int> dp1(first.size(), -1);
    vector<int> dp2(second.size(), -1);

    return max(solve(first, 0, dp1), solve(second, 0, dp2));
}