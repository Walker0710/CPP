#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

//only rec
int solve(vector<int> &nums, int index, int flag) {

    if(index >= nums.size()) 
    return 0;

    int ans = 0;

    if(nums[index] - nums[index-1] > 0 && flag) {

        ans = 1 + solve(nums, index+1, 0);
    }

    else if(nums[index] - nums[index-1] < 0 && !flag) {

        ans = 1 + solve(nums, index+1, 1);
    }

    else {
        ans = solve(nums, index+1, flag);
    }

    return ans;
}

int wiggleMaxLength(vector<int>& nums) {

    return 1 + max(solve(nums, 1, 1), solve(nums, 1, 0));
}

//rec + mem
int solveMem(vector<int> &nums, int index, int flag, vector<vector<int>> &dp) {

    if(index >= nums.size()) 
    return 0;

    if(dp[index][flag] != -1)
    return dp[index][flag];

    int ans = 0;

    if(nums[index] - nums[index-1] > 0 && flag) {

        ans = 1 + solveMem(nums, index+1, 0, dp);
    }

    else if(nums[index] - nums[index-1] < 0 && !flag) {

        ans = 1 + solveMem(nums, index+1, 1, dp);
    }

    else {
        ans = solveMem(nums, index+1, flag, dp);
    }

    return dp[index][flag] = ans;
}

int wiggleMaxLength(vector<int>& nums) {

    vector<vector<int>> dp(nums.size()+1, vector<int> (2, -1));
    return 1 + max(solveMem(nums, 1, 1, dp), solveMem(nums, 1, 0, dp));
}
