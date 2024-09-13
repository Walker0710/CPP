#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
int solve(vector<int> &nums, int index, int prev) {

    if(index >= nums.size()) 
    return 0;

    int ans = 0;
    int include = 0;
    int exclude = 0;

    if(nums[index] > prev) {

        include = 1 + solve(nums, index+1, nums[index]);
        
    }
    exclude = solve(nums, index+1, prev);
    
    ans = max(include, exclude);
    return ans;
}

int lengthOfLIS(vector<int>& nums) {
    return solve(nums, 0, INT_MIN);
}

//tabulation
int solveTab(int n, vector<int> &nums)
{
    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr-1; prev >= -1; prev--)
        {  
            int include = 0;

            if (prev == -1 || nums[curr] > nums[prev])
            include = 1 + dp[curr+1][curr+1];

            int exclude = 0 + dp[curr+1][prev+1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int lengthOfLIS(vector<int>& nums) {
    return solveTab(nums.size(), nums);
}




















