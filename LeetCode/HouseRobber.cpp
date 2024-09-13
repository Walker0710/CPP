#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

//only rec
int solve(vector<int> &nums, int index) {

    if(index >= nums.size())
    return 0;

    int include = nums[index] + solve(nums, index+2);
    int exclude = solve(nums, index+1);

    int ans = max(include, exclude);
    return ans;
}

int rob(vector<int>& nums) {

    return solve(nums, 0);
}

//rec + mem
int solveMem(vector<int> &nums, int index, vector<int> &dp) {

    if(index >= nums.size())
    return 0;

    if(dp[index] != -1)
    return dp[index];

    int include = nums[index] + solveMem(nums, index+2, dp);
    int exclude = solveMem(nums, index+1, dp);

    int ans = max(include, exclude);
    return dp[index] = ans;
}

int rob(vector<int>& nums) {
    
    vector<int> dp(nums.size(), -1);
    return solveMem(nums, 0, dp);
}



