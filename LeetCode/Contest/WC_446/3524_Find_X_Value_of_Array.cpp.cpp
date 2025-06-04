#include <bits/stdc++.h>

using namespace std;

// << ,

long long gg(int i, int x, int mul, int k, vector<int> &a, vector<vector<long long>> &dp)
{
    if (i == a.size())
    return 0;
    
    if (dp[i][mul + 1] != -1)
    return dp[i][mul + 1];

    long long opt1 = 0;
    long long opt2 = 0;
    long long ct = 0;

    if (mul == -1)
    {
        if (a[i] == x)
            ct++;
        opt1 = ct + gg(i + 1, x, a[i], k, a, dp);
        opt2 = gg(i + 1, x, -1, k, a, dp);
    }

    else
    {
        if ((mul * a[i]) % k == x)
            ct++;
        opt1 = ct + gg(i + 1, x, (mul * a[i]) % k, k, a, dp);
    }

    return dp[i][mul + 1] = opt1 + opt2;
}

vector<long long> resultArray(vector<int> &a, int k)
{
    int n = a.size();
    vector<long long> res;
 
    for (int i = 0; i < n; i++)
    {
        a[i] %= k;
    }
 
    vector<vector<long long>> dp;
 
    for (int x = 0; x < k; x++)
    {
        dp.assign(n, vector<long long>(k + 1, -1));
        res.push_back(gg(0, x, -1, k, a, dp));
    }
 
    return res;
}