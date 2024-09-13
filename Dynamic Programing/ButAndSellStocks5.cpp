#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

int solveTab(vector<int> &prices, int fee)
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
                int include = prices[index] + next[1] - fee;
                int excluded = 0 + next[0];

                profit += max(include, excluded);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}

int maxProfit(vector<int> &prices, int fee)
{
    return solveTab(prices, fee);
}