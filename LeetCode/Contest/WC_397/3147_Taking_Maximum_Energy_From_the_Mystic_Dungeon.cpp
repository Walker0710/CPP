#include <bits/stdc++.h>

using namespace std;

// << ,

int rec(int ind, int ans, vector<int> &energy, int k, vector<int> &dp)
{
    if (ind >= energy.size())
    return 0;
    
    if (dp[ind] != INT_MIN)
    return dp[ind];

    dp[ind] = energy[ind] + rec(ind + k, ans, energy, k, dp);

    return dp[ind];
}

int maximumEnergy(vector<int> &energy, int k)
{
    int n = energy.size();
    int ans = INT_MIN;
    vector<int> dp(n, INT_MIN);
 
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, rec(i, ans, energy, k, dp));
    }
 
    return ans;
}