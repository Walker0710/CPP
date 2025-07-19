#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[101][101];

int ways(int n, vector<int> &coins, int in)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0 || in >= coins.size())
    {
        return 0;
    }

    if (dp[n][in] != -1)
    {
        return dp[n][in];
    }

    int ans = ways(n, coins, in + 1) + ways(n - coins[in], coins, in);

    return dp[n][in] = ans;
}

vector<int> findCoins(vector<int> &numWays)
{
    vector<int> coin;

    for (int i = 0; i < numWays.size(); i++)
    {

        memset(dp, -1, sizeof(dp));
        int totalWaysWithoutCoin = ways(i + 1, coin, 0);

        if (totalWaysWithoutCoin == numWays[i])
        {
            continue;
        }

        else
        {
            coin.push_back(i + 1);

            memset(dp, -1, sizeof(dp));
            int totalWaysWithCoin = ways(i + 1, coin, 0);

            if (numWays[i] != totalWaysWithCoin)
            {
                coin = vector<int>();
                return coin;
            }
        }
    }

    return coin;
}