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

using namespace std;

// << ,

//only rec
int solve(string s, int i, string t, int j)
{
    if (j == t.length())
    return 1;

    if (i == s.length())
    return 0;

    int ans = 0;
    int inc = 0;
    int exc = 0;

    if (s[i] == t[j])
    {
        inc = solve(s, i + 1, t, j + 1);
    }

    exc = solve(s, i + 1, t, j);

    ans = inc + exc;

    return ans;
}

int numDistinct(string s, string t)
{
    return solve(s, 0, t, 0);
}

//rec + memo
int solve(string &s, int i, string &t, int j, vector<vector<int>> &dp) {
    if (j == t.length()) 
        return 1;

    if (i == s.length())
        return 0;

    if (dp[i][j] != -1) 
        return dp[i][j];

    int inc = 0;
    int exc = 0;

    if (s[i] == t[j]) {
        inc = solve(s, i + 1, t, j + 1, dp);
    }

    exc = solve(s, i + 1, t, j, dp);

    dp[i][j] = inc + exc;

    return dp[i][j];
}

int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solve(s, 0, t, 0, dp);
}