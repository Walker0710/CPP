#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int jump, int back, map<array<int, 3>, int> &dp, int k)
{
    if (i > k + 1)
    {
        return 0;
    }

    if (dp.count({i, jump, back}))
    {
        return dp[{i, jump, back}];
    }

    int ans = (i == k);
    
    if (back == 1 && i > 0)
    {
        ans += solve(i - 1, jump, 0, dp, k);
    }
    
    ans += solve(i + pow(2, jump), jump + 1, 1, dp, k);
    
    return dp[{i, jump, back}] = ans;
}

int waysToReachStair(int k)
{
    map<array<int, 3>, int> dp;
    
    return solve(1, 0, 1, dp, k);
}