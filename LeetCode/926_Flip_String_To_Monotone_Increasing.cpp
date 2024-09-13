#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

bool isMono(string s)
{

    int i = 0;
    bool mono = true;

    while (i < s.length() && s[i] == '0')
        i++;

    while (i < s.length() && s[i] == '1')
        i++;

    if (i != s.length())
        mono = false;

    return mono;
}

int solve(string &s, int index)
{

    if (index == s.length() - 1 && isMono(s))
        return 0;

    if (index >= s.length())
        return INT_MAX - 300;

    int ans = 0;

    // not flipping
    int notFliping = solve(s, index + 1);

    // flipping
    int fliping = 0;

    if (s[index] == '1')
    {
        s[index] = '0';
        fliping = 1 + solve(s, index + 1);
    }

    else
    {
        s[index] = '1';
        fliping = 1 + solve(s, index + 1);
    }

    ans = min(fliping, notFliping);
    return ans;
}

int minFlipsMonoIncr(string s)
{
    return solve(s, 0);
}

// rec

int solve(int i, int prev, string &s, int n, vector<vector<int>> &dp)
{
    if (i >= n)
        return 0;

    if (dp[i][prev] != -1)
        return dp[i][prev];

    int ans = INT_MAX;

    if (s[i] == '0')
    {
        if (prev == 0)
        {
            ans = min(1 + solve(i + 1, 1, s, n, dp), solve(i + 1, 0, s, n, dp));
        }
        else
        {
            ans = 1 + solve(i + 1, 1, s, n, dp);
        }
    }
    else
    {
        if (prev == 0)
        {
            ans = min(1 + solve(i + 1, 0, s, n, dp), solve(i + 1, 1, s, n, dp));
        }
        else
        {
            ans = solve(i + 1, 1, s, n, dp);
        }
    }

    return dp[i][prev] = ans;
}

int minFlipsMonoIncr(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    int res = solve(0, 0, s, n, dp);
    return res;
}

// tabulation
int minFlipsMonoIncr(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX - 300));

    dp[n][0] = dp[n][1] = 0;

    int prev = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = 1; prev >= 0; prev--)
        {

            int ans = INT_MAX;

            if (s[i] == '0')
            {
                if (prev == 0)
                {
                    ans = min(1 + dp[i + 1][1], dp[i + 1][0]);
                }
                else
                {
                    ans = 1 + dp[i + 1][1];
                }
            }
            else
            {
                if (prev == 0)
                {
                    ans = min(1 + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    ans = dp[i + 1][1];
                }
            }
            dp[i][prev] = ans;
        }
    }

    return dp[0][0];
}

int minFlipsMonoIncr(string s)
{
    int n = s.size();
    vector<int> post(n); // keeps the count of number of '0's to the right
    post[n - 1] = (s[n - 1] == '0') ? 1 : 0;
    for (int i = n - 2; i >= 0; i--)
        post[i] = post[i + 1] + (s[i] == '0' ? 1 : 0);

    int currFlips = 0, ans = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            int toFlip = (i + 1 == n) ? 0 : post[i + 1];
            int totalFlips = currFlips + toFlip; // make all the 0's to 1's towards right
            ans = min(ans, totalFlips);          // record the answer

            // or
            currFlips++; // just flip the current '1' to '0' and move
        }
    }

    ans = min(ans, currFlips);
    return ans;
}