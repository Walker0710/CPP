#include <bits/stdc++.h>

using namespace std;

// << ,

bool solveMem(int index, string s, unordered_map<string, int> &map, vector<int> &dp)
{
    if (index == s.length())
        return true;

    if (dp[index] != -1)
    {
        return dp[index];
    }

    for (int i = index; i < s.length(); i++)
    {
        if (map.count(s.substr(index, i - index + 1)) && solveMem(i + 1, s, map, dp))
        {
            dp[i + 1] = 1;
            return true;
        }
    }
    dp[index] = 0;
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, int> map;
    vector<int> dp(s.size() + 1, -1);

    for (auto i : wordDict)
    {
        map[i]++;
    }

    return solveMem(0, s, map, dp);
}





bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    return dfs(s, wordSet, 0);
}

bool dfs(const string &s, const unordered_set<string> &wordSet, int i)
{
    if (i == s.size())
    {
        return true;
    }

    for (int j = i; j < s.size(); j++)
    {
        if (wordSet.find(s.substr(i, j - i + 1)) != wordSet.end())
        {
            if (dfs(s, wordSet, j + 1))
            {
                return true;
            }
        }
    }
    return false;
}





// 2nd bottom up
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, int> map;
    vector<int> dp(s.size() + 1, 0);

    for (auto i : wordDict)
    {
        map[i]++;
    }

    for (int index = s.length() - 1; index >= 0; index--)
    {

        for (int i = index; i < s.length(); i++)
        {
            if (map.count(s.substr(index, i - index + 1)) && dp[i + 1])
            {
                dp[i + 1] = 1;
            }
        }

        dp[index] = 0;
    }

    return dp[0];
}