#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only rec
int solve(vector<int> &prices, int index, int buy, int count)
{
    if (index >= prices.size())
        return 0;

    if (count <= 0)
        return 0;

    int profit = 0;

    if (buy)
    {
        int include = -prices[index] + solve(prices, index + 1, 0, count);
        int excluded = solve(prices, index + 1, 1, count);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solve(prices, index + 1, 1, count - 1);
        int excluded = solve(prices, index + 1, 0, count);

        profit += max(include, excluded);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    return solve(prices, 0, 1, 2);
}

// using 3D dp
int solveMem(vector<int> &prices, int index, int buy, int count, vector<vector<vector<int>>> &dp)
{
    if (index >= prices.size())
        return 0;

    if (count <= 0)
        return 0;

    if (dp[index][buy][count] != -1)
        return dp[index][buy][count];

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
    return dp[index][buy][count] = profit;
}

int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solveMem(prices, 0, 1, 2, dp);
}

// Tablulation
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int count = 1; count <= 2; count++)
            {
                int profit = 0;

                if (buy)
                {
                    int include = -prices[index] + dp[index + 1][0][count - 1];
                    int excluded = dp[index + 1][1][count];

                    profit += max(include, excluded);
                }

                else
                {
                    int include = prices[index] + dp[index + 1][1][count - 1];
                    int excluded = dp[index + 1][0][count];

                    profit += max(include, excluded);
                }
                dp[index][buy][count] = profit;
            }
        }
    }

    return dp[0][1][2];
}

int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}

//space opptimization easy h kar lena 

