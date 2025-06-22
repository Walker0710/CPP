#include <bits/stdc++.h>

using namespace std;

// << ,
int solve(int index, int win, char last, string &s, unordered_map<char, char> &winMap, unordered_map<char, char> &lossMap)
{
    if (index == s.length())
        return win >= (s.length() + 1) / 2;

    int winn = 0;
    int draw = 0;
    int loss = 0;

    // win
    if (last != winMap[s[index]])
    {
        winn = solve(index + 1, win + 1, winMap[s[index]], s, winMap, lossMap);
    }

    // draw
    if (last != s[index])
    {
        draw = solve(index + 1, win, s[index], s, winMap, lossMap);
    }

    // loss
    if (last != lossMap[s[index]])
    {
        loss = solve(index + 1, win, lossMap[s[index]], s, winMap, lossMap);
    }

    return winn + draw + loss;
}

int countWinningSequences(string s)
{
    unordered_map<char, char> winMap;
    winMap['F'] = 'W';
    winMap['W'] = 'E';
    winMap['E'] = 'F';

    unordered_map<char, char> lossMap;
    lossMap['F'] = 'E';
    lossMap['W'] = 'F';
    lossMap['E'] = 'W';

    return solve(0, 0, 'T', s, winMap, lossMap);
}



int MOD = 1e9 + 7;
int dp[3][1001][2001];

long long solveMem(string &s, int prev, int curr, long long bob)
{
    if (curr >= s.size())
    {
        return bob > 0 ? 1 : 0;
    }

    if (dp[prev][curr][bob + 1000] != -1)
        return dp[prev][curr][bob + 1000];

    long long f = 0, w = 0, e = 0;
    if (s[curr] == 'F')
    {
        if (prev != 0)
            f = solveMem(s, 0, curr + 1, bob) % MOD % MOD;
        if (prev != 1)
            w = solveMem(s, 1, curr + 1, bob + 1) % MOD;
        if (prev != 2)
            e = solveMem(s, 2, curr + 1, bob - 1) % MOD;
    }
    else if (s[curr] == 'W')
    {
        if (prev != 0)
            f = solveMem(s, 0, curr + 1, bob - 1) % MOD;
        if (prev != 1)
            w = solveMem(s, 1, curr + 1, bob) % MOD;
        if (prev != 2)
            e = solveMem(s, 2, curr + 1, bob + 1) % MOD;
    }
    else
    {
        if (prev != 0)
            f = solveMem(s, 0, curr + 1, bob + 1) % MOD;
        if (prev != 1)
            w = solveMem(s, 1, curr + 1, bob - 1) % MOD;
        if (prev != 2)
            e = solveMem(s, 2, curr + 1, bob) % MOD;
    }

    return dp[prev][curr][bob + 1000] = (f + w + e);
}

int countWinningSequences(string s)
{
    long long ans = 0;
    int n = s.size();
    memset(dp, -1, sizeof(dp));

    ans = (solveMem(s, 0, 0, 0) + solveMem(s, 1, 0, 0) + solveMem(s, 2, 0, 0));

    return (ans / 2) % MOD;
}