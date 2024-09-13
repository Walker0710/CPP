#include<iostream>
#include<vector>

using namespace std;

//only Rec
int solve(vector<int> &nums, int tar) {

    int sum1 = 0;

    if(tar == 0) 
    return 1;

    if(tar < 0)
    return 0;

    for(int i = 0; i<nums.size(); i++) {

        int ans = solve(nums, tar - nums[i]);
        sum1 += ans;
    }

    return sum1;
}

int findWays(vector<int> &num, int tar) {
    
    return solve(num, tar);
}

//Rec + memo
int solveMem(vector<int> &nums, int tar, vector<int> &dp) {

    int sum = 0;

    if(tar == 0) 
    return 1;

    if(tar < 0)
    return 0;

    if(dp[tar] !=  -1)
    return dp[tar];

    for(int i = 0; i<nums.size(); i++) {

        sum += solveMem(nums, tar - nums[i], dp);
    }

    dp[tar] = sum;
    return dp[tar];
}

int findWays(vector<int> &num, int tar) {

    vector<int> dp(tar + 1, -1);
    return solveMem(num, tar, dp);
}

//Tabulation
int solveTab(vector<int> &nums, int tar) {

    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for(int i = 1; i<=tar; i++) {

        for(int j = 0; j<nums.size(); j++) {

            if(i-nums[j] >= 0)
            dp[i] = dp[i] + dp[i - nums[j]];
        }
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar) {

    return solveTab(num, tar);
}


