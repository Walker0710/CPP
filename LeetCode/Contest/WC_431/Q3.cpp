#include <bits/stdc++.h>

using namespace std;

// << ,

long long maximumCoins(vector<vector<int>> &coins, int k)
{
    long long res = 0, sum = 0;
    sort(begin(coins), end(coins));
    
    for (int i = 0, j = 0; i < coins.size(); ++i)
    {
        long long l = coins[i][0], r = coins[i][1], c = coins[i][2];
        sum += (r - l + 1) * c;
    
        while (r - k + 1 > coins[j][1])
        {
            if (coins[j][0] + k - 1 >= l)
            res = max(res, sum - (r - (coins[j][0] + k - 1)) * c);
    
            sum -= ((long long)coins[j][1] - coins[j][0] + 1) * coins[j][2];
            ++j;
        }
    
        if (coins[j][0] + k - 1 >= r)
        res = max(res, sum);
        
        else
        {
            res = max(res, sum - (r - k + 1 - coins[j][0]) * coins[j][2]);
    
            if (coins[j][0] + k - 1 >= l)
            res = max(res, sum - (r - (coins[j][0] + k - 1)) * c);
        }
    }
    
    return res;
}


long long maximumCoins(vector<vector<int>> &coins, int k)
{
    int maxEnd = 0;

    for (auto &coin : coins)
        maxEnd = max(maxEnd, coin[1]);

    vector<long long> path(maxEnd + 2, 0);

    for (auto &coin : coins)
    {
        int start = coin[0], end = coin[1], value = coin[2];
        path[start] += value;
        path[end + 1] -= value;
    }

    for (int i = 1; i <= maxEnd + 1; ++i)
        path[i] += path[i - 1];

    long long sum = 0;

    for (int i = 0; i < k && i <= maxEnd + 1; ++i)
        sum += path[i];

    long long maxSum = sum;

    for (int i = k; i <= maxEnd + 1; ++i)
    {
        sum += path[i] - path[i - k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
