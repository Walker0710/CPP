#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

int solveTab(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // 1 Day
        int cost1 = costs[0] + dp[i + 1];

        // 7 Day
        int passEndDate = days[i] + 6;
        int j = i;
        while (j < days.size() and days[j] <= passEndDate)
        {
            j++;
        }
        int cost7 = costs[1] + dp[j];

        // 30 Day
        passEndDate = days[i] + 29;
        j = i;
        while (j < days.size() and days[j] <= passEndDate)
        {
            j++;
        }
        int cost30 = costs[2] + dp[j];

        dp[i] = min(cost1, min(cost7, cost30));
    }

    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solveTab(days, costs);
}