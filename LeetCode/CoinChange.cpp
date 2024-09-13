#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

//only rec
int solve(vector<int> &coins, int amount) {

    if(amount == 0) 
    return 0;

    if(amount < 0)
    return INT_MAX - 2;

    int ans = INT_MAX;

    for(int index = 0; index < coins.size(); index++) {

        ans = min(ans, 1+solve(coins, amount - coins[index]));
    }

    return ans;
}

int coinChange(vector<int>& coins, int amount) {

    int ans = solve(coins, amount);

    if(ans == 2147483647 || ans == 2147483646)
    return -1;

    return ans;
}

//mem + rec
int solveMem(vector<int> &coins, int amount, vector<int> &dp) {

    if(amount == 0) 
    return 0;

    if(amount < 0)
    return INT_MAX;

    if(dp[amount] != -1)
    return dp[amount];

    int ans = INT_MAX;

    for(int index = 0; index < coins.size(); index++) {

        int yo = solveMem(coins, amount - coins[index], dp);
        if(yo != INT_MAX)
        ans = min(ans, 1+yo);
    }

    return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount) {

    vector<int> dp(amount+1, -1);
    int ans = solveMem(coins, amount, dp);

    if(ans == 2147483647 || ans == 2147483646)
    return -1;

    return ans;
}