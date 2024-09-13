#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

// rec only
// first approch
int solve(vector<int> &nums1, vector<int> &nums2, int i, int j, int prev)
{
    if (i = nums1.size() || (i == nums1.size() && j == nums2.size()))
        return 0;

    else if (j == nums2.size())
    {
        if (prev == nums2.size() - 1)
            return 0;

        return solve(nums1, nums2, i++, prev + 1, prev);
    }

    int ans = 0;
    int inc = 0;
    int exc = 0;

    if (nums1[i] == nums2[j])
    inc = 1 + solve(nums1, nums2, i + 1, j + 1, j);

    else 
    exc = solve(nums1, nums2, i, j + 1, prev);

    ans = max(inc, exc);

    return ans;
}

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    return solve(nums1, nums2, 0, 0, 0);
}

// second approch
int fun(int idx1, int idx2, int n, int m, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
{
    if (idx1 == n || idx2 == m)
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (nums1[idx1] == nums2[idx2])
    {
        return dp[idx1][idx2] = 1 + fun(idx1 + 1, idx2 + 1, n, m, nums1, nums2, dp);
    }

    else
    {
        return dp[idx1][idx2] = max(fun(idx1 + 1, idx2, n, m, nums1, nums2, dp), fun(idx1, idx2 + 1, n, m, nums1, nums2, dp));
    }
}

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(0, 0, n, m, nums1, nums2, dp);
}

// tabulation
int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

    for (int i = 0; i <= n; i++)
        dp[i][m] = 0;

    for (int i = 0; i <= m; i++)
        dp[n][i] = 0;

    for (int i = n - 1; i >= 0; i++)
    {
        for (int j = m - 1; j >= 0; j++)
        {

            if (nums1[i] == nums2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }

            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    dp[0][0];
}