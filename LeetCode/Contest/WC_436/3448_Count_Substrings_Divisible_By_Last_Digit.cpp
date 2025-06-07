#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int ind, string &s, vector<int> &dp)
{
    if (ind == s.length())
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int ans = 0;

    ans += solve(ind + 1, s, dp);

    long long num = 0;
    for (int i = ind; i < s.length(); i++)
    {
        num = num * 10 + (s[i] - '0');

        int lastDigit = s[i] - '0';
        if (lastDigit != 0 && num % lastDigit == 0)
        {
            ans += 1;
        }
    }

    return dp[ind] = ans;
}

long long countSubstrings(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, -1);
    return solve(0, s, dp);
}

int solve(int ind, string &s, vector<int> &dp)
{
    if (ind == s.length())
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int ans = 0;

    ans += solve(ind + 1, s, dp);

    for (int i = ind; i < s.length(); i++)
    {
        int lastDigit = s[i] - '0';

        if (lastDigit == 0)
            continue;

        long long numMod = 0;
        for (int j = ind; j <= i; j++)
        {
            numMod = (numMod * 10 + (s[j] - '0')) % lastDigit;
        }

        if (numMod == 0)
        {
            ans += 1;
        }
    }

    return dp[ind] = ans;
}

long long countSubstrings(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, -1);
    return solve(0, s, dp);
}












long long dp[100005][10][2];

long long recursion(int pos, int rem, bool isStarted, int lastDigit, int n, vector<int> &v)
{
    if (pos == n)
        return 0;

    if (dp[pos][rem][isStarted] != -1)
    {
        return dp[pos][rem][isStarted];
    }

    long long ans = 0;

    if (!isStarted)
    {
        // If the substring is not started then either we can start or skip the current pos.
        ans += recursion(pos + 1, rem, isStarted, lastDigit, n, v);

        int newRem = v[pos] % lastDigit;

        if (v[pos] == lastDigit && newRem == 0)
            ans++;

        ans += recursion(pos + 1, newRem, isStarted ^ 1, lastDigit, n, v);
    }

    if (isStarted)
    {
        // If the substring is started then we can continue it.
        int newRem = (rem * 10 + v[pos]) % lastDigit;
        
        if (v[pos] == lastDigit && newRem == 0)
            ans++;

        ans += recursion(pos + 1, newRem, isStarted, lastDigit, n, v);
    }

    return dp[pos][rem][isStarted] = ans;
}

long long countSubstrings(string s)
{
    int n = s.size();

    vector<int> v;
    for (auto &x : s)
    {
        v.push_back(x - '0');
    }

    long long ans = 0;
    for (int lastDigit = 1; lastDigit <= 9; lastDigit++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = -1;
            }
        }

        ans += recursion(0, 0, 0, lastDigit, n, v);
    }

    return ans;
}