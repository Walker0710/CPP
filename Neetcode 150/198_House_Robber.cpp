#include <bits/stdc++.h>

using namespace std;

// << ,

//meme

int solve(vector<int> &nums, int index, vector<int> &dp) {
    if(index >= nums.size()) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    //inc
    int inc = nums[index] + solve(nums, index+2, dp);

    int exc = solve(nums, index + 1, dp);

    return dp[index] = max(inc, exc);
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums, 0, dp);
}


//tabulation
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    }

    return dp[n-1];
}


//space opt
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    // vector<int> dp(n);
    int prev = nums[0];
    int curr = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        int temp = max(curr, nums[i] + prev);
        prev = curr;
        curr = temp;
    }

    return curr;
}