#include <bits/stdc++.h>

using namespace std;

// << ,

int solveMem(vector<int> &coins, int amount, int starting, vector<vector<int>> &dp)
{

    if (amount == 0)
        return 1;

    if (amount < 0)
        return 0;

    if (dp[amount][starting] != -1)
        return dp[amount][starting];

    int ans = 0;

    for (int i = starting; i < coins.size(); i++)
    {

        ans = ans + solveMem(coins, amount - coins[i], i, dp);
    }
    return dp[amount][starting] = ans;
}

int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
    return solveMem(coins, amount, 0, dp);
}

int change(int amount, vector<int> &coins)
{
    sort(coins.begin(), coins.end());
    vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));

    return dfs(0, amount, coins, memo);
}

int dfs(int i, int a, vector<int> &coins, vector<vector<int>> &memo)
{
    if (a == 0)
        return 1;

    if (i >= coins.size())
        return 0;

    if (memo[i][a] != -1)
        return memo[i][a];

    int res = 0;

    if (a >= coins[i])
    {
        res = dfs(i + 1, a, coins, memo);
        res += dfs(i, a - coins[i], coins, memo);
    }

    memo[i][a] = res;
    return res;
}



// tabulation
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    sort(coins.begin(), coins.end());
    vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int a = 0; a <= amount; a++)
        {
            if (a >= coins[i])
            {
                dp[i][a] = dp[i + 1][a];
                dp[i][a] += dp[i][a - coins[i]];
            }
        }
    }

    return dp[0][amount];
}