#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
int solve(vector<int>& nums, int index) {

    if(index >= nums.size()) 
    return 0;

    int include = nums[index] + solve(nums, index + 2);
    int exclude = 0 + solve(nums, index+1);

    return max(include, exclude);
}

int rob(vector<int>& nums) {

    int n = nums.size();

    if(n == 1) 
    return nums[0];

    vector<int> first, second;

    for(int i = 0; i<n; i++) {

        if(i != n-1)
        first.push_back(nums[i]);

        if(i != 0)
        second.push_back(nums[i]);
    }

    return max(solve(first, 0), solve(second, 0));
}

//mem + rec
int solveMem(vector<int>& nums, int index, vector<int> &dp) {

    if(index >= nums.size()) 
    return 0;

    if(dp[index] != -1) 
    return dp[index];

    int include = nums[index] + solveMem(nums, index + 2, dp);
    int exclude = 0 + solveMem(nums, index+1, dp);

    return dp[index] = max(include, exclude);
}

int rob(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp1(nums.size(), -1);
    vector<int> dp2(nums.size(), -1);

    if(n == 1) 
    return nums[0];

    vector<int> first, second;

    for(int i = 0; i<n; i++) {

        if(i != n-1)
        first.push_back(nums[i]);

        if(i != 0)
        second.push_back(nums[i]);
    }

    return max(solveMem(first, 0, dp1), solveMem(second, 0, dp2));
}
