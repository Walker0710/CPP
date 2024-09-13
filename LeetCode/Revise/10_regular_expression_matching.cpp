#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    int n = s.size();
    int m = p.size();

    if (j == m)
    {
        return (i == n);
    }
    
    if (dp[i][j] != -1)
    return dp[i][j];
    
    bool nextStar = false;

    if (j + 1 < m && p[j + 1] == '*')
    nextStar = true;

    if (nextStar)
    {
        bool a = false, b = false;

        if (i < n && (s[i] == p[j] || p[j] == '.'))
        a = solve(i + 1, j, s, p, dp);
        
        b = solve(i, j + 2, s, p, dp);

        return dp[i][j] = (a || b);
    }

    else
    {
        if (i < n && (s[i] == p[j] || p[j] == '.'))
        return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
    }
    
    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    return solve(0, 0, s, p, dp);
}