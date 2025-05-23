#include <bits/stdc++.h>

using namespace std;

// << ,

// rec + mem
int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
{

    if (curr == n)
        return 0;

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    int include = 0;

    if (prev == -1 || a[curr] > a[prev])
        include = 1 + solveMem(n, a, curr + 1, curr, dp);

    int exclude = 0 + solveMem(n, a, curr + 1, prev, dp);

    dp[curr][prev + 1] = max(include, exclude);

    return dp[curr][prev + 1];
}

int longestSubsequence(int n, int a[])
{

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveMem(n, a, 0, -1, dp);
}

// tabulation
int solveTab(int n, int a[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;

            if (prev == -1 || a[curr] > a[prev])
                include = 1 + dp[curr + 1][curr + 1];

            int exclude = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }

    return dp[0][0];
}