#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only rec
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

pair<int, int> solve2(string &s, int st, int en)
{

    if (st > en)
        return {0, 0};

    if (pali(s, st, en))
    {
        return {st, en};
    }

    else
    {

        pair<int, int> one = solve2(s, st + 1, en);
        pair<int, int> two = solve2(s, st, en - 1);

        int firstDiff = one.second - one.first;
        int secondDiff = two.second - two.first;

        if (firstDiff > secondDiff)
            return one;

        else
            return two;
    }
}

string longestPalindrome(string s)
{

    if (s.length() == 1)
        return s;

    pair<int, int> yo = solve2(s, 0, s.length() - 1);
    string ans = s.substr(yo.first, yo.second - yo.first + 1);
    return ans;
}

// rec + mem
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

// tabulation
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

// 2nd approch
string longestPalindrome(string s)
{
    if (s == string(s.rbegin(), s.rend()))
    {
        return s;
    }

    string left = longestPalindrome(s.substr(1));
    string right = longestPalindrome(s.substr(0, s.size() - 1));

    if (left.length() > right.length())
    {
        return left;
    }

    else
    {
        return right;
    }
}

//Manacher's algo
std::string longestPalindrome(std::string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    int maxLen = 1;
    std::string maxStr = s.substr(0, 1);
    s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
    std::vector<int> dp(s.length(), 0);
    int center = 0;
    int right = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (i < right)
        {
            dp[i] = std::min(right - i, dp[2 * center - i]);
        }

        while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1])
        {
            dp[i]++;
        }

        if (i + dp[i] > right)
        {
            center = i;
            right = i + dp[i];
        }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
            maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
        }
    }

    return maxStr;
}
