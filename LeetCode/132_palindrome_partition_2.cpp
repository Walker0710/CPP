#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>
#include <cstring>

using namespace std;

// << ,

// first approch
bool isPalin(string s)
{
    int st = 0;
    int en = s.length() - 1;

    while (st < en)
    {
        if (s[st] != s[en])
            return false;

        st++;
        en--;
    }

    return true;
}

int solve(string s)
{
    if (isPalin(s))
        return 0;

    int ans = INT_MAX;

    for (int i = 1; i < s.length(); i++)
    {
        ans = min(ans, 1 + solve(s.substr(0, i)) + solve(s.substr(i)));
    }

    return ans;
}

int minCut(string s)
{
    return solve(s);
}

// sec approch
int n;
bool isPalindrome(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l++] != s[r--])
        {
            return false;
        }
    }
    return true;
}
int solve(string &s, int idx)
{
    if (idx >= n)
    {
        return 0;
    }
    int minSteps = INT_MAX;
    for (int k = idx; k < n; k++)
    {
        if (isPalindrome(s, idx, k))
        {
            int steps = 1 + solve(s, k + 1);
            minSteps = min(minSteps, steps);
        }
    }
    return minSteps;
}
int minCut(string s)
{
    n = s.size();
    return solve(s, 0) - 1;
}

// rec + memo

int n;
int memo[2000];
bool isPalindrome(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l++] != s[r--])
        {
            return false;
        }
    }
    return true;
}
int solve(string &s, int idx)
{
    if (idx >= n)
    {
        return 0;
    }
    if (memo[idx] != -1)
    {
        return memo[idx];
    }
    int minSteps = INT_MAX;
    for (int k = idx; k < n; k++)
    {
        if (isPalindrome(s, idx, k))
        {
            int steps = 1 + solve(s, k + 1);
            minSteps = min(minSteps, steps);
        }
    }
    return memo[idx] = minSteps;
}
int minCut(string s)
{
    n = s.size();
    memset(memo, -1, sizeof(memo));
    return solve(s, 0) - 1;
}
