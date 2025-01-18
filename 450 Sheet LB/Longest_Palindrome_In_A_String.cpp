#include <bits/stdc++.h>

using namespace std;

// << ,

// Mem
bool pali(string &s, int st, int en)
{
    while (en >= st)
    {
        if (s[en] != s[st])
            return false;

        en--;
        st++;
    }

    return true;
}

pair<int, int> solveMem(string &s, int st, int en, vector<vector<pair<int, int>>> &dp)
{
    if (st > en)
        return {0, 0};

    if (dp[st][en].first != -1)
        return dp[st][en];

    if (pali(s, st, en))
    {
        return {st, en};
    }

    else
    {
        pair<int, int> one = solveMem(s, st + 1, en, dp);
        pair<int, int> two = solveMem(s, st, en - 1, dp);

        int firstDiff = one.second - one.first;
        int secondDiff = two.second - two.first;

        if (firstDiff > secondDiff)
            return dp[st][en] = one;

        else
            return dp[st][en] = two;
    }
}

string longestPalindrome(string s)
{
    if (s.length() == 1)
        return s;

    vector<vector<pair<int, int>>> dp(s.length() + 1, vector<pair<int, int>>(s.length() + 1, {-1, -1}));

    pair<int, int> yo = solveMem(s, 0, s.length() - 1, dp);

    string ans = s.substr(yo.first, yo.second - yo.first + 1);

    return ans;
}

// Tab

bool pali(string &s, int st, int en)
{
    while (en >= st)
    {
        if (s[en] != s[st])
            return false;

        en--;
        st++;
    }

    return true;
}

string longestPalindrome(string s)
{
    if (s.length() == 1)
        return s;

    vector<vector<pair<int, int>>> dp(s.length() + 1, vector<pair<int, int>>(s.length() + 1, {0, 0}));

    for (int st = s.length() - 1; st >= 0; st--)
    {
        for (int en = 0; en < s.length(); en++)
        {
            if (pali(s, st, en))
            {
                dp[st][en] = {st, en};
            }

            else
            {

                pair<int, int> one = dp[st + 1][en];
                pair<int, int> two = dp[st][en - 1];

                int firstDiff = one.second - one.first;
                int secondDiff = two.second - two.first;

                if (firstDiff > secondDiff)
                    dp[st][en] = one;

                else
                    dp[st][en] = two;
            }
        }
    }
    pair<int, int> yo = dp[0][s.length() - 1];
    string ans = s.substr(yo.first, yo.second - yo.first + 1);
    return ans;
}