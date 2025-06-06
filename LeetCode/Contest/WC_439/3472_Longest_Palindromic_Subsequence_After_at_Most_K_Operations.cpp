#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[202][202][202];

int solve(int i, int j, string &s, int k)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int res = 0;

    if (s[i] == s[j])
    {
        res = 2 + solve(i + 1, j - 1, s, k);
    }

    else
    {
        int cost = min((s[i] - s[j] + 26) % 26, (s[j] - s[i] + 26) % 26);
        if (k >= cost)
        {
            res = 2 + solve(i + 1, j - 1, s, k - cost);
        }
    }

    // Try skipping i or skipping j
    res = max({res, solve(i + 1, j, s, k), solve(i, j - 1, s, k)});

    return dp[i][j][k] = res;
}

int longestPalindromicSubsequence(string s, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, s.length() - 1, s, k);
}