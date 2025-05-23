#include <bits/stdc++.h>

using namespace std;

// << ,

// Gready doesnt work
int coinChange(vector<int> &coins, int amount)
{
    int ans = 0;
    int i = 0;
    sort(coins.rbegin(), coins.rend());

    while (amount > 0 && i < coins.size())
    {
        if (coins[i] > amount)
        {
            i++;
            continue;
        }

        int coin = amount / coins[i];

        ans = ans + coin;
        amount = amount - coin * coins[i];

        i++;
    }

    if (amount != 0 && i == coins.size())
        return -1;

    return ans;
}

// dp, memo
int solveMem(vector<int> &coins, int amount, vector<int> &dp)
{

    if (amount == 0)
        return 0;

    if (amount < 0)
        return INT_MAX - 2;

    if (dp[amount] != -1)
        return dp[amount];

    int ans = INT_MAX;

    for (int index = 0; index < coins.size(); index++)
    {

        int yo = solveMem(coins, amount - coins[index], dp);
        if (yo != INT_MAX)
            ans = min(ans, 1 + yo);
    }

    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{

    vector<int> dp(amount + 1, -1);
    int ans = solveMem(coins, amount, dp);

    if (ans == 2147483647 || ans == 2147483646)
        return -1;

    return ans;
}


// bottom up
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX - 5);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int index = 0; index < coins.size(); index++)
        {
            if (i >= coins[index])
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[index]]);
            }
        }
    }

    if(dp[amount] == INT_MAX - 5)
    return -1;

    return dp[amount];
}