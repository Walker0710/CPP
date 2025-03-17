#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// only rec
int solve(int n, int a[], int curr, int prev)
{

    if (curr == n)
        return 0;

    int include = 0;
    int exclude = 0;

    if (prev == -1 || a[curr] > a[prev])
        include = 1 + solve(n, a, curr + 1, curr);

    exclude = 0 + solve(n, a, curr + 1, prev);

    return max(include, exclude);
}

int longestSubsequence(int n, int a[])
{
    return solve(n, a, 0, -1);
}














// Algorithms
int solve(int n, int a[], int curr, int prev1, int prev2)
{

    if (curr == n)
        return 0;

    int include = 0;
    int exclude = 0;

    if (prev2 == -2)
    {
        include = 1 + solve(n, a, curr + 1, prev1, curr);
    }

    else if (prev1 == -1 && a[curr] > a[prev2])
    {
        include = 1 + solve(n, a, curr + 1, curr, prev2);
    }

    else if (a[curr] - a[prev1] >  a[prev1] - a[prev2])
    {
        include = 1 + solve(n, a, curr + 1, curr, prev1);
    }

    exclude = 0 + solve(n, a, curr + 1, prev);

    return max(include, exclude);
}

int longestSubsequence(int n, int a[])
{
    return solve(n, a, 0, -1, -2);
}



















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

int longestSubsequence(int n, int a[])
{
    return solveTab(n, a);
}

// space optimization
int solveTab2(int n, int a[])
{
    vector<int> next(n + 1, 0);
    vector<int> current(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;

            if (prev == -1 || a[curr] > a[prev])
                include = 1 + next[curr + 1];

            int exclude = 0 + next[prev + 1];

            current[prev + 1] = max(include, exclude);
        }
        next = current;
    }
    return next[0];
}

int longestSubsequence(int n, int a[])
{
    return solveTab2(n, a);
}

// using Binary Search
int solveOptimal(int n, int a[])
{

    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);

    for (int i = 0; i < n; i++)
    {

        if (a[i] > ans.back())
            ans.push_back(a[i]);

        else
        {

            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, int a[])
{
    return solveOptimal(n, a);
}
