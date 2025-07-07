#include <bits/stdc++.h>

using namespace std;

// << ,
long long solve(int sx, int ex, int sy, int ey, vector<int> &h, vector<int> &v, vector<vector<vector<vector<int>>>> &dp)
{
    if (sx == ex && sy == ey)
    return 0;
    
    else if (sx > ex || sy > ey)
    return 0;

    else if (dp[sx][ex][sy][ey] != -1)
    return dp[sx][ex][sy][ey];

    long long ans = INT_MAX;

    for (int i = sx; i < ex; i++)
    {
        ans = min(ans, solve(sx, i, sy, ey, h, v, dp) + solve(i + 1, ex, sy, ey, h, v, dp) + v[i]);
    }

    for (int i = sy; i < ey; i++)
    {
        ans = min(ans, solve(sx, ex, sy, i, h, v, dp) + solve(sx, ex, i + 1, ey, h, v, dp) + h[i]);
    }

    dp[sx][ex][sy][ey] = ans;
    return ans;
}

int minimumCost(int m, int n, vector<int> &h, vector<int> &v)
{
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1))));
    return solve(0, n - 1, 0, m - 1, h, v, dp);
}