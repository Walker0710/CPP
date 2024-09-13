#include <iostream>
#include <vector>
#include <limits.h>
#include<queue>

using namespace std;

// only Rec
int solve(int n, vector<int> &days, vector<int> &cost, int index)
{

    if (index >= n)
        return 0;

    // for 1 day pass
    int option1 = cost[0] + solve(n, days, cost, index + 1);

    // for 7 day pass
    int i = 0;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solve(n, days, cost, i);

    // for 30 day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    return solve(n, days, cost, 0);
}

// Rec + Mem
int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{

    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // for 1 day pass
    int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp);

    // for 7 day pass
    int i = 0;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solveMem(n, days, cost, i, dp);

    // for 30 day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));

    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    vector<int> dp(n + 1, -1);
    return solveMem(n, days, cost, 0, dp);
}

// Tabulation
int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {

        int option1 = cost[0] + dp[n + 1];

        int i = 0;
        for (i = k; i < n && days[i] < days[k] + 7; i++);
        int option2 = cost[1] + dp[i];

        // for 30 day pass
        for (i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

//Tabulation + space optimization
int minimumCoins(int n, vector<int> days, vector<int> cost) {

    int ans = 0;

    queue<pair<int, int>> monthly;
    queue<pair<int, int>> weekly;

    for(auto day : days) {

        while(!monthly.empty() && monthly.front().first + 30 <= day)
        monthly.pop();

        while(!weekly.empty() && weekly.front().first + 7 <= day)
        weekly.pop();

        weekly.push(make_pair(day, ans + cost[1]));
        monthly.push(make_pair(day, ans + cost[2]));

        ans = min(ans+cost[0], min(weekly.front().second, monthly.front().second));
    }

    return ans;
}

