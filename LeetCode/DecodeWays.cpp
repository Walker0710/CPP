#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// rec onLy
int solve2(string &s, int index)
{

    if (index == s.length())
        return 1;

    if (index > s.length() || s[index] == '0')
        return 0;

    int ans = 0;

    if (s[index + 1] != '0')
        ans = ans + solve2(s, index + 1);

    if ((s[index] == '2' || s[index] == '1') && (s[index + 1] <= '6'))
        ans = ans + solve2(s, index + 2);

    return ans;
}

int numDecodings(string s)
{

    if (s.empty() || s[0] == '0')
        return 0;

    else
        return solve2(s, 0);
}

// TLE
int solve2(string &s, int index)
{

    if (index == s.length())
        return 1;

    if (index > s.length() || s[index] == '0')
        return 0;

    int ans = 0;

    if (s[index + 1] != '0')
        ans = ans + solve2(s, index + 1);

    if (index + 1 < s.length() && ((s[index] == '1') || (s[index] == '2' && s[index + 1] <= '6'))) // if((s[index] == '2' || s[index] == '1') &&  (s[index+1] <= '6'))
        ans = ans + solve2(s, index + 2);

    return ans;
}

int numDecodings(string s)
{

    if (s.empty() || s[0] == '0')
        return 0;

    else
        return solve2(s, 0);
}

// Rec + Mem
int solveMem(string &s, int index, vector<int> &dp)
{

    if (index == s.length())
        return 1;

    if (index > s.length() || s[index] == '0')
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int ans = 0;

    if (s[index + 1] != '0')
        ans = ans + solveMem(s, index + 1, dp);

    if (index + 1 < s.length() && ((s[index] == '1') || (s[index] == '2' && s[index + 1] <= '6'))) // if((s[index] == '2' || s[index] == '1') &&  (s[index+1] <= '6'))
        ans = ans + solveMem(s, index + 2, dp);

    return dp[index] = ans;
}

int numDecodings(string s)
{

    if (s.empty() || s[0] == '0')
        return 0;

    else
    {
        vector<int> dp(s.length() + 1, -1);
        return solveMem(s, 0, dp);
    }
}

// Tabulation
int solveTab(string &s)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        int ans = 0;

        if (s[index] == '0')
        {
            dp[index] = 0;
            continue;
        }

        if (s[index + 1] != '0')
            ans = ans + dp[index + 1];

        if (index + 1 < s.length() && ((s[index] == '1') || (s[index] == '2' && s[index + 1] <= '6')))
            ans = ans + dp[index + 2];

        dp[index] = ans;
    }

    return dp[0];
}

int numDecodings(string s)
{
    if (s.empty() || s[0] == '0')
        return 0;

    return solveTab(s);
}
