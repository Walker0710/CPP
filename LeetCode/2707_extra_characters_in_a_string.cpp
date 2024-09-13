#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

// only rec
int solve(int i, int j, string &s, unordered_set<string> &map)
{
    if (j == s.length())
    {
        return (map.find(s.substr(i, j - i)) != map.end()) ? 0 : j - i;
    }

    int first = INT_MAX;
    int second = INT_MAX;

    if (map.find(s.substr(i, j - i + 1)) != map.end())
        first = solve(j + 1, j + 1, s, map);

    else
        first = j - i + 1 + solve(j + 1, j + 1, s, map);

    second = solve(i, j + 1, s, map);

    return min(first, second);
}

int minExtraChar(string s, vector<string> &dictionary)
{
    unordered_set<string> map;

    for (auto i : dictionary)
    {
        map.insert(i);
    }

    return solve(0, 0, s, map);
}

// rec + mem
int solveMem(int i, int j, string &s, unordered_set<string> &map, vector<vector<int>> &dp)
{
    if (j == s.length())
    {
        return (map.find(s.substr(i, j - i)) != map.end()) ? 0 : j - i;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int first = INT_MAX;
    int second = INT_MAX;

    if (map.find(s.substr(i, j - i + 1)) != map.end())
        first = solveMem(j + 1, j + 1, s, map, dp);

    else
        first = j - i + 1 + solveMem(j + 1, j + 1, s, map, dp);

    second = solveMem(i, j + 1, s, map, dp);
    return min(first, second);
}

int minExtraChar(string s, vector<string> &dictionary)
{
    unordered_set<string> map;
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));

    for (auto i : dictionary)
    {
        map.insert(i);
    }

    return solveMem(0, 0, s, map, dp);
}

// third
unordered_map<string, int> memo;

int solve(int i, int j, string &s, unordered_set<string> &map)
{
    if (j == s.length())
    {
        return (map.find(s.substr(i, j - i)) != map.end()) ? 0 : j - i;
    }

    string key = to_string(i) + "," + to_string(j);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    int first = INT_MAX;
    int second = INT_MAX;

    if (map.find(s.substr(i, j - i + 1)) != map.end())
    {
        first = solve(j + 1, j + 1, s, map);
    }
    else
    {
        first = j - i + 1 + solve(j + 1, j + 1, s, map);
    }

    second = solve(i, j + 1, s, map);

    memo[key] = min(first, second);
    return memo[key];
}

int minExtraChar(string s, vector<string> &dictionary)
{
    unordered_set<string> map(dictionary.begin(), dictionary.end());
    memo.clear();
    return solve(0, 0, s, map);
}

// trying for 1D array
int solve(const string &s, int idx, const vector<string> &dictionary, vector<int> &dp)
{
    int n = s.size();
    if (idx == n)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int ans = 1 + solve(s, idx + 1, dictionary, dp);
    int m, jdx;
    for (auto &word : dictionary)
    {
        m = word.size();
        if (m + idx > n)
            continue;
        bool match = true;
        jdx = idx;
        for (auto &ch : word)
        {
            if (s[jdx] != ch)
            {
                match = false;
                break;
            }
            jdx++;
        }
        if (match)
            ans = min(ans, solve(s, idx + m, dictionary, dp));
    }
    return dp[idx] = ans;
}

int minExtraChar(string s, vector<string> &dictionary)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solve(s, 0, dictionary, dp);
}