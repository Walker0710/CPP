#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

//only rec
int solve(vector<int>& prices, int index, int buy) {

    if(index >= prices.size())
    return 0;

    int profit = 0;

    if (buy)
    {
        int include = -prices[index] + solve(prices, index + 1, 0);
        int excluded = solve(prices, index + 1, 1);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solve(prices, index + 2, 1);
        int excluded = solve(prices, index + 1, 0);

        profit += max(include, excluded);
    }

    return profit;
}

int maxProfit(vector<int>& prices) {

    return solve(prices, 0, 1);
}

//rec + mem
int solveMem(vector<int>& prices, int index, int buy, vector<vector<int>> &dp) {

    if(index >= prices.size())
    return 0;

    if(dp[index][buy] != -1)
    return dp[index][buy];

    int profit = 0;

    if (buy)
    {
        int include = -prices[index] + solveMem(prices, index + 1, 0, dp);
        int excluded = solveMem(prices, index + 1, 1, dp);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solveMem(prices, index + 2, 1, dp);
        int excluded = solveMem(prices, index + 1, 0, dp);

        profit += max(include, excluded);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int>& prices) {

    vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
    return solveMem(prices, 0, 1, dp);
}
