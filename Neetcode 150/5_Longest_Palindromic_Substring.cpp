#include <bits/stdc++.h>

using namespace std;

// << ,
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

// 2nd approch

string longestPalindrome(string s)
{
    if(s.length() == 1)
    return s;

    vector<string> dp(s.length() + 1, "");

    return solve(s, i, j, dp);
}