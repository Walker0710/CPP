#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

// only rec
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        // Combine hashes of the two integers
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

bool isPali(string s, int st, int en)
{

    while (st <= en)
    {
        if (s[st] != s[en])
            return false;

        st++;
        en--;
    }

    return true;
}

int solve(string &s, int st, int en, unordered_map<pair<int, int>, bool, pair_hash> &m)
{

    if (st > en)
        return 0;

    int ans = 0;
    int first = 0;
    int second = 0;

    if (isPali(s, st, en) && m[make_pair(st, en)] == false)
    {
        m[make_pair(st, en)] = true;
        ans = 1 + solve(s, st + 1, en, m) + solve(s, st, en - 1, m);
    }

    else
    {
        ans = 0 + solve(s, st + 1, en, m) + solve(s, st, en - 1, m);
    }

    return ans;
}

int countSubstrings(string s)
{
    unordered_map<pair<int, int>, bool, pair_hash> m;
    return solve(s, 0, s.length() - 1, m);
}

// rec + mem
int solveMem(string &s, int st, int en, unordered_map<pair<int, int>, bool, pair_hash> &m, vector<vector<int>> &dp)
{

    if (st > en)
        return 0;

    if (dp[st][en] != -1)
        return dp[st][en];

    int ans = 0;
    int first = 0;
    int second = 0;

    if (isPali(s, st, en) && m[make_pair(st, en)] == false)
    {
        m[make_pair(st, en)] = true;
        ans = 1 + solveMem(s, st + 1, en, m, dp) + solveMem(s, st, en - 1, m, dp);
    }

    else
    {
        ans = 0 + solveMem(s, st + 1, en, m, dp) + solveMem(s, st, en - 1, m, dp);
    }

    return dp[st][en] = ans;
}

int countSubstrings(string s)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
    unordered_map<pair<int, int>, bool, pair_hash> m;
    return solveMem(s, 0, s.length() - 1, m, dp);
}

//Manacher’s Algorithm – Linear Time Longest Palindromic Substring
int countSubstrings(string &s)
{
    int n = s.size(), N = 2 * n + 1;
    // Expanded string for s
    string t = "$";
    for (char c : s)
    {
        t.push_back(c);
        t.push_back('$');
    }

    // pRad[i]=radius for max palindromic x[i] substring of t centered at i
    // pRad[i]=len of palindromic substring of s corresponding to x[i]
    vector<int> pRad(N, 0);
    int c = 0, radius = 0;
    for (int i = 0; i < N; i++)
    {
        int reflex = 2 * c - i;
        if (i < radius)
        {
            pRad[i] = min(radius - i, pRad[reflex]);
        }
        int r = i + 1 + pRad[i], l = i - 1 - pRad[i];
        while (r < N && l >= 0 && t[r] == t[l])
        {
            pRad[i]++;
            r++, l--;
        }
        if (i + pRad[i] > radius)
        {
            c = i;
            radius = i + pRad[i];
        }
    }
    //    print(pRad);
    int ans = 0;
    for (int r : pRad)
        ans += (r + 1) / 2;
    return ans;
}
