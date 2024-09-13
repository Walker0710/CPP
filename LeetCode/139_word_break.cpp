#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solve(int index, string s, unordered_map<string, int> &map)
{
    if (index == s.length())
        return true;

    for (int i = index; i < s.length(); i++)
    {
        if (map.count(s.substr(index, i - index + 1)) && solve(i + 1, s, map))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, int> map;

    for (auto i : wordDict)
    {
        map[i]++;
    }

    return solve(0, s, map);
}

// memo
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
        if (map.count(s.substr(index, i - index + 1)) && solveMem(i + 1, s, map, dp));
        {
            dp[i+1] = 1;
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
