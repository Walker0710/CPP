#include <bits/stdc++.h>

using namespace std;

// << ,

// rec + memo

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j == t.length())
        return 1;

    if (i == s.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = solve(s, t, i + 1, j + 1, dp) + solve(s, t, i + 1, j, dp);
    }

    else
    {
        return dp[i][j] = solve(s, t, i + 1, j, dp);
    }
}

int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solve(s, t, 0, 0, dp);
}

// tabulation

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j == t.length())
        return 1;

    if (i == s.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = solve(s, t, i + 1, j + 1, dp) + solve(s, t, i + 1, j, dp);
    }

    else
    {
        return dp[i][j] = solve(s, t, i + 1, j, dp);
    }
}

int numDistinct(string s, string t)
{
    int m = s.length(), n = t.length();
    vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][n] = 1; 
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    return dp[0][0];
}