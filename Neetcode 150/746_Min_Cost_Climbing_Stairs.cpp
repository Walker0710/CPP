#include <bits/stdc++.h>

using namespace std;

// << ,

// 1st approch
int solve(vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= cost.size())
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    dp[index] = cost[index] + min(solve(cost, index + 1, dp), solve(cost, index + 2, dp));

    return dp[index];
}

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size(), -1);
    return min(solve(cost, 0, dp), solve(cost, 1, dp));
}

// 2nd approch

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < cost.size(); i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
}
