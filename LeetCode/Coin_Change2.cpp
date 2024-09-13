#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std; 

//only rec
int solve(vector<int> &coins, int amount, int starting) {

    if(amount == 0) 
    return 1;

    if(amount < 0)
    return 0;

    int ans = 0;

    for(int i = starting; i<coins.size(); i++) {

        ans = ans + solve(coins, amount - coins[i], i);
    }
    return ans;
}

int change(int amount, vector<int>& coins) {

    return solve(coins, amount, 0);
}

//rec + mem
int solveMem(vector<int> &coins, int amount, int starting, vector<vector<int>> &dp) {

    if(amount == 0) 
    return 1;

    if(amount < 0)
    return 0;

    if(dp[amount][starting] != -1)
    return dp[amount][starting];

    int ans = 0;

    for(int i = starting; i<coins.size(); i++) {

        ans = ans + solveMem(coins, amount - coins[i], i, dp);
    }
    return dp[amount][starting] = ans;
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(amount+1, vector<int> (coins.size()+1, -1));
    return solveMem(coins, amount, 0, dp);
}

//tabulation 
int solveTab(int amount, vector<int>& coins) {

    vector<vector<int>> dp(amount+1, vector<int> (coins.size()+1, 0));

    for(int i = 0; i<=coins.size(); i++) 
    dp[0][i] = 1;

    for(int target = 0; target <= amount; target++) {

        for(int starting = coins.size() - 1; starting >= 0; starting--) {

            int ans = 0;

            for(int i = starting; i<coins.size(); i++) {

                if(target - coins[i] >= 0)
                ans = ans + dp[target - coins[i]][i];
            }

            dp[target][starting] = ans;
        }
    }

    return dp[amount][0];
}

int change(int amount, vector<int>& coins) {
    return solveTab(amount, coins);
}

//optimized approch





