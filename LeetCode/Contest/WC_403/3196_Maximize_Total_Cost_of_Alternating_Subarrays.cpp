#include <bits/stdc++.h>

using namespace std;

// << ,

long long solve(int index, bool flag, vector<int> &nums,vector<vector<long long>> &dp) {
    if(index == nums.size()) {
        return 0;
    }

    if(dp[index][flag] != -1)
    return dp[index][flag];

    long long conti = nums[index]*(flag == true ? 1 : -1) + solve(index + 1, !flag, nums, dp);
    long long newSt = nums[index] + solve(index+1, false, nums, dp);

    return dp[index][flag] = max(conti, newSt);
}

long long maximumTotalCost(vector<int> &nums)
{   
    vector<vector<long long>> dp(nums.size()+1, vector<long long> (2, -1));
    return solve(0, true, nums, dp);
}