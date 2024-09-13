#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//omly Rec
int solve(vector<int> &nums, int n) {

    if(n < 0) 
    return 0;

    if(n == 0)
    return nums[0];

    int include = solve(nums, n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;

    return max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();
    int ans = solve(nums, n-1);
    return ans;
}

// Rec + memo
int solve(vector<int> &nums, int n, vector<int> &dp) {

    if(n < 0) 
    return 0;

    if(n == 0)
    return nums[0];

    if(dp[n] != -1)
    return dp[n];

    int include = solve(nums, n-2, dp) + nums[n];
    int exclude = solve(nums, n-1, dp) + 0;

    dp[n] = max(include, exclude);

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n+1, -1);
    int ans = solve(nums, n-1, dp);
    return ans;
}

//Tabulation
int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for(int i = 1; i<n; i++) {

        dp[i] = max((dp[i-2] + nums[i]), dp[i-1]);
    }
    return dp[n-1];
}

//Tabulation with space optimization
int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i<n; i++) {

        int curr = max(prev1, prev2 + nums[i]);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}