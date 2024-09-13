#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only rec
int solve(vector<int> &prices, int index, int buy)
{
    if (index >= prices.size())
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
        int include = prices[index] + solve(prices, index + 1, 1);
        int excluded = solve(prices, index + 1, 0);

        profit += max(include, excluded);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{

    return solve(prices, 0, 1);
}

// rec + mem
int solveMem(vector<int> &prices, int index, int buy, vector<vector<int>> &dp)
{

    if (index >= prices.size())
        return 0;

    if (dp[index][buy] != -1)
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

        int include = prices[index] + solveMem(prices, index + 1, 1, dp);
        int excluded = solveMem(prices, index + 1, 0, dp);

        profit += max(include, excluded);
    }

    dp[index][buy] = profit;

    return dp[index][buy];
}

int maxProfit(vector<int> &prices)
{

    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return solveMem(prices, 0, 1, dp);
}

// tabulation
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;

            if (buy)
            {
                int include = -prices[index] + dp[index + 1][0];
                int excluded = 0 + dp[index + 1][1];

                profit += max(include, excluded);
            }

            else
            {
                int include = prices[index] + dp[index + 1][1];
                int excluded = 0 + dp[index + 1][0];

                profit += max(include, excluded);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}

//space optmization
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int include = -prices[index] + next[0];
                int excluded = 0 + next[1];

                profit += max(include, excluded);
            }

            else
            {
                int include = prices[index] + next[1];
                int excluded = 0 + next[0];

                profit += max(include, excluded);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}

int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}


