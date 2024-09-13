#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

//only rec
int solve(int target) {
    if(target < 0) 
        return INT_MAX;

    if(target == 0)
        return 0;

    int ans = INT_MAX;

    for(int i = 1; i*i <= target; i++) {
        ans = std::min(ans, 1 + solve(target - i*i));
    }

    return ans;
}

int numSquares(int n) {
    return solve(n);
}

//rec + mem
int solveMem(int target, vector<int> &dp) {

    if(target < 0) 
        return INT_MAX;

    if(target == 0)
        return 0;

    if(dp[target] != -1)
    return dp[target];

    int ans = INT_MAX;

    for(int i = 1; i*i <= target; i++) {
        ans = min(ans, 1 + solveMem(target - i*i, dp));
    }

    return dp[target] = ans;
}

int numSquares(int n) {
    vector<int> dp(n+1, -1);
    return solveMem(n, dp);
}

//tabulation
int solveTab(int n) {

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int target = 0; target<= n; target++) {

        int ans = INT_MAX;

        for(int i = 1; i*i <= target; i++) {
            
            if(target - i*i >= 0)
            ans = min(ans, 1 + dp[target - i*i]);
        }

        dp[target] = ans;
    }

    return dp[n];
}

int numSquares(int n) {
    return solveTab(n);
}

