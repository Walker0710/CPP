#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

pair<int, int> counting(const string &s)
{
    int zero = 0;
    int one = 0;

    for (char c : s)
    {
        if (c == '0')
            zero++;

        else if (c == '1')
            one++;
    }
    return {zero, one};
}

int solve(vector<string> &strs, int m, int n, int index)
{

    if (index >= strs.size())
        return 0;

    if (m == 0 && n == 0)
        return 0;

    if (m < 0 || n < 0)
        return INT_MIN;

    int size = 0;

    // include
    int zeros = counting(strs[index]).first;
    int ones = counting(strs[index]).second;
    int include = 1 + solve(strs, m - zeros, n - ones, index + 1);

    // exclude
    int exclude = 0 + solve(strs, m, n, index + 1);

    size = max(include, exclude);
    return size;
}

int findMaxForm(vector<string> &strs, int m, int n)
{

    return solve(strs, m, n, 0);
}

//leetcode sol
int dp[601][101][101];
int dfs(int i, int m, int n, vector<string> &strs)
{
    int x = strs.size();
    if (i >= x)
        return 0;
    if (dp[i][m][n] != -1)
        return dp[i][m][n];
    int zc = count(strs[i].begin(), strs[i].end(), '0');
    int oc = size(strs[i]) - zc;
    if (m - zc >= 0 && n - oc >= 0)
    {
        return dp[i][m][n] = max(1 + dfs(i + 1, m - zc, n - oc, strs), dfs(i + 1, m, n, strs));
    }
    else
    {
        return dp[i][m][n] = dfs(i + 1, m, n, strs);
    }
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    memset(dp, -1, sizeof(dp));
    return dfs(0, m, n, strs);
}
