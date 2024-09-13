#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only recursion
int solve(int k, vector<int> &prices, int index, int buy, int limit)
{
    if (index >= prices.size())
        return 0;

    if (limit <= 0)
        return 0;

    int profit = 0;

    if (buy)
    {
        int include = -prices[index] + solve(k, prices, index + 1, 0, limit);
        int excluded = solve(k, prices, index + 1, 1, limit);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solve(k, prices, index + 1, 1, limit - 1);
        int excluded = solve(k, prices, index + 1, 0, limit);

        profit += max(include, excluded);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int limit = k;
    return solve(k, prices, 0, 1, limit);
}

// Rec + mem
int solveMem(int k, vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
{
    if (index >= prices.size())
        return 0;

    if (limit <= 0)
        return 0;

    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;

    if (buy)
    {
        int include = -prices[index] + solveMem(k, prices, index + 1, 0, limit, dp);
        int excluded = solveMem(k, prices, index + 1, 1, limit, dp);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solveMem(k, prices, index + 1, 1, limit - 1, dp);
        int excluded = solveMem(k, prices, index + 1, 0, limit, dp);

        profit += max(include, excluded);
    }
    return dp[index][buy][limit] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    int limit = k;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(limit + 1, -1)));
    return solveMem(k, prices, 0, 1, limit, dp);
}

// babbar's approch we can use 2D arr for mem in this approch
int solveYo(int index, int operationNo, int k, vector<int> &prices)
{
    if (index >= prices.size())
        return 0;

    if (operationNo >= 2 * k)
        return 0;

    int profit = 0;

    if (operationNo % 2 == 0)
    {
        int include = -prices[index] + solveYo(index + 1, operationNo + 1, k, prices);
        int excluded = solveYo(index + 1, operationNo, k, prices);

        profit += max(include, excluded);
    }

    else
    {
        int include = prices[index] + solveYo(index + 1, operationNo + 1, k, prices);
        int excluded = solveYo(index + 1, operationNo, k, prices);

        profit += max(include, excluded);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    return solveYo(0, 0, k, prices);
}

// Tabulation
int solveTab(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 2, 0));

    for (int index = n - 1; index >= 0; index--)
    {

        for (int operationNo = 2 * k; operationNo >= 0; operationNo--)
        {
            int profit = 0;

            if (operationNo % 2 == 0)
            {
                int include = -prices[index] + dp[index + 1][operationNo + 1];
                int excluded = dp[index + 1][operationNo]; 

                profit += max(include, excluded);
            }

            else
            {
                int include = prices[index] + dp[index + 1][operationNo + 1];
                int excluded = dp[index + 1][operationNo];

                profit += max(include, excluded);
            }

            dp[index][operationNo] = profit;
        }
    }

    return dp[0][0];
}

int maxProfit(int k, vector<int> &prices)
{
    return solveTab(k, prices);
}
