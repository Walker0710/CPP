#include <bits/stdc++.h>

using namespace std;

// << ,
int solveMem(vector<int> &prices, int index, int buy, int count, vector<vector<int>> &dp)
{
    if (index >= prices.size())
        return 0;

    if (count <= 0)
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;

    if (buy)
    {
        int include = -prices[index] + solveMem(prices, index + 1, 0, count, dp);
        int excluded = solveMem(prices, index + 1, 1, count, dp);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solveMem(prices, index + 1, 1, count - 1, dp);
        int excluded = solveMem(prices, index + 1, 0, count, dp);

        profit += max(include, excluded);
    }
    return dp[index][buy] = profit;
}


int maxProfit(vector<int> &prices)
{
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return solveMem(prices, 0, 1, 2, dp);
}