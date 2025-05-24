#include <bits/stdc++.h>

using namespace std;

// << ,

// rec + memo
bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    int n = s.size();
    int m = p.size();

    if (j == m)
    {
        return (i == n);
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    bool nextStar = false;

    if (j + 1 < m && p[j + 1] == '*')
        nextStar = true;

    if (nextStar)
    {
        bool a = false, b = false;

        if (i < n && (s[i] == p[j] || p[j] == '.'))
            a = solve(i + 1, j, s, p, dp);

        b = solve(i, j + 2, s, p, dp);

        return dp[i][j] = (a || b);
    }

    else
    {
        if (i < n && (s[i] == p[j] || p[j] == '.'))
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
    }

    return dp[i][j] = false;
}

bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    return solve(0, 0, s, p, dp);
}

// tabulation
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[n][m] = 1;


    // ye imp h
    for (int j = m - 1; j >= 0; j--)
    {
        if (j + 1 < m && p[j + 1] == '*')
        {
            dp[n][j] = dp[n][j + 2];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            bool nextStar = false;

            if (j + 1 < m && p[j + 1] == '*')
                nextStar = true;

            if (nextStar)
            {
                bool a = false, b = false;

                if (i < n && (s[i] == p[j] || p[j] == '.'))
                    a = dp[i + 1][j];

                b = dp[i][j + 2];

                dp[i][j] = (a || b);
            }

            else
            {
                if (i < n && (s[i] == p[j] || p[j] == '.'))
                    dp[i][j] = dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}