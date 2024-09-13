#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solve(int index, vector<int> &arr, int k, vector<int> &dp)
{
    if (index == arr.size())
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int ans = 0;
    int maxSoFar = 0;

    for (int j = index; j < min(index + k, (int)arr.size()); j++)
    {
        maxSoFar = max(maxSoFar, arr[j]);
        int potentialBreak = maxSoFar * (j - index + 1) + solve(j + 1, arr, k, dp);

        ans = max(ans, potentialBreak);
    }

    return dp[index] = ans;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    vector<int> dp(arr.size(), -1);

    return solve(0, arr, k, dp);
}

// tabulation
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[n] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        int ans = 0;
        int maxSoFar = 0;

        for (int j = index; j < min(index + k, (int)arr.size()); j++)
        {
            maxSoFar = max(maxSoFar, arr[j]);
            int potentialBreak = maxSoFar * (j - index + 1) + dp[j + 1];

            ans = max(ans, potentialBreak);
        }
        dp[index] = ans;
    }

    return dp[0];
}