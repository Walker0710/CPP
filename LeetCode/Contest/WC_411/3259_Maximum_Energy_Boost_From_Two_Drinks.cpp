#include <bits/stdc++.h>

using namespace std;

// << ,

long long solve(vector<int> &a, vector<int> &b, int i, int k, vector<vector<long long>> &dp)
{
    if (i == a.size())
    {
        return 0;
    }
    if (dp[k][i] != -1)
    return dp[k][i];
    
    long long take = 0, nottake = 0;
    
    if (k == 1)
    {
        take = a[i] + solve(a, b, i + 1, k, dp);
        nottake = solve(a, b, i + 1, 2, dp);
    }
    
    else if (k == 2)
    {
        take = b[i] + solve(a, b, i + 1, k, dp);
        nottake = solve(a, b, i + 1, 1, dp);
    }
    
    return dp[k][i] = max(take, nottake);
}

long long maxEnergyBoost(vector<int> &a, vector<int> &b)
{
    vector<vector<long long>> dp(3, vector<long long>(a.size(), -1));
    return max(solve(a, b, 0, 1, dp), solve(a, b, 0, 2, dp));
}