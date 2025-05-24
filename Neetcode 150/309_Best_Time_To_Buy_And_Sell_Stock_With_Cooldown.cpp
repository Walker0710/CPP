#include <bits/stdc++.h>

using namespace std;

// << ,

// rec + meme

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
        int include = prices[index] + solveMem(prices, index + 2, 1, dp);
        int excluded = solveMem(prices, index + 1, 0, dp);

        profit += max(include, excluded);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int> &prices)
{

    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solveMem(prices, 0, 1, dp);
}

// Tabulation
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); 

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;

            if (buy)
            {
                int include = -prices[index] + dp[index + 1][0];
                int exclude = dp[index + 1][1];
                profit = max(include, exclude);
            }
            else
            {
                int include = prices[index] + dp[index + 2][1];
                int exclude = dp[index + 1][0];
                profit = max(include, exclude);
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}
