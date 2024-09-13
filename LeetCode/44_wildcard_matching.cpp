#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

//rec only
bool solve(int i, int j, string &s, string &p)
{
    int n = s.length();
    int m = p.length();

    if (j == m)
    {
        return (i == n);
    }

    if (i == n)
    return (p[j] == '*' && solve(i, j+1, s, p));

    if (i < n && (s[i] == p[j] || p[j] == '?'))
    {
        return solve(i + 1, j + 1, s, p);
    }

    if (p[j] == '*')
    {
        bool a = solve(i + 1, j, s, p);
        bool b = solve(i, j + 1, s, p);

        return (a || b);
    }

    return false;
}

bool isMatch(string s, string p)
{
    return solve(0, 0, s, p);
}

//rec + mem
bool solveMem(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    int n = s.length();
    int m = p.length();

    if (j == m)
    {
        return (i == n);
    }

    if (i == n)
    return (p[j] == '*' && solveMem(i, j+1, s, p, dp));

    if(dp[i][j] != -1)
    return dp[i][j];

    if (i < n && (s[i] == p[j] || p[j] == '?'))
    {
        return dp[i][j] = solveMem(i + 1, j + 1, s, p, dp);
    }

    if (p[j] == '*')
    {
        bool a = solveMem(i + 1, j, s, p, dp);
        bool b = solveMem(i, j + 1, s, p, dp);

        return dp[i][j] = (a || b);
    }

    return dp[i][j] = false;
}

bool isMatch(string s, string p)
{   
    vector<vector<int>> dp(s.length() + 1, vector<int> (p.length() + 1, -1));
    return solveMem(0, 0, s, p, dp);
}
