#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
bool solve(string s, int index1, string t, int index2)
{

    if (index1 == s.length())
        return true;

    else if (index2 == t.length())
        return false;

    if (s[index1] == t[index2])
        return solve(s, index1 + 1, t, index2 + 1);

    else
        return solve(s, index1, t, index2 + 1);
}

bool isSubsequence(string s, string t)
{
    return solve(s, 0, t, 0);
}

// rec + mem
bool solveMem(string s, int index1, string t, int index2, vector<vector<int>> &dp)
{

    if (index1 == s.length())
        return true;

    else if (index2 == t.length())
        return false;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    if (s[index1] == t[index2])
        return dp[index1][index2] = solveMem(s, index1 + 1, t, index2 + 1, dp);

    else
        return dp[index1][index2] = solveMem(s, index1, t, index2 + 1, dp);
}

bool isSubsequence(string s, string t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
    return solveMem(s, 0, t, 0, dp);
}

// Tabulation
bool solveTab(string &s, string &t)
{

    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));

    for (int i = 0; i <= t.length(); i++)
        dp[s.length()][i] = 1;

    for (int index1 = s.length() - 1; index1 >= 0; index1--)
    {

        for (int index2 = t.length() - 1; index2 >= 0; index2--)
        {

            if (s[index1] == t[index2])
                dp[index1][index2] = dp[index1 + 1][index2 + 1];

            else
                dp[index1][index2] = dp[index1][index2 + 1];
        }
    }

    return dp[0][0];
}

bool isSubsequence(string s, string t)
{
    return solveTab(s, t);
}