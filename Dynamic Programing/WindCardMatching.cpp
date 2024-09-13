#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <stack>

using namespace std;

// only rec
bool solve(string &s, string &p, int i, int j)
{

    if (i < 0 && j < 0)
        return true;

    if (i >= 0 && j < 0)
        return false;

    if (i < 0 && j >= 0)
    {

        for (int k = 0; k <= j; k++)
        {

            if (p[k] != '*')
                return false;
        }
        return true;
    }

    // if matches
    if (s[i] == p[j] || p[j] == '?')
        return solve(s, p, i - 1, j - 1);

    else if (p[j] == '*')
        return (solve(s, p, i - 1, j) || solve(s, p, i, j - 1));

    else
        return false;
}

bool isMatch(string s, string p)
{

    return solve(s, p, s.length() - 1, p.length() - 1);
}

// rec + mem
bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0 && j < 0)
        return true;

    if (i >= 0 && j < 0)
        return false;

    if (i < 0 && j >= 0)
    {

        for (int k = 0; k <= j; k++)
        {

            if (p[k] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // if matches
    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = solveMem(s, p, i - 1, j - 1, dp);

    else if (p[j] == '*')
        return dp[i][j] = (solveMem(s, p, i - 1, j, dp) || solveMem(s, p, i, j - 1, dp));

    else
        return dp[i][j] = false;
}

bool isMatch(string s, string p)
{

    vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
    return solveMem(s, p, s.length() - 1, p.length() - 1, dp);
}

// Tabulation
int solveTab(string &s, string &p)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));
    dp[0][0] = true;

    for (int j = 1; j <= p.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (p[j-1] == '*')
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);

            else
                dp[i][j] = false;
        }
    }
    return dp[s.length()][p.length()];
}

bool isMatch(string s, string p)
{
    return solveTab(s, p);
}
