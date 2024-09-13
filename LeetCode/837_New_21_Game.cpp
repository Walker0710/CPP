#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
double solve(int n, int k, int pt, int maxPts)
{

    if (pt >= k && pt <= n)
        return 1.0;

    if (pt >= k && pt > n)
        return 0.0;

    double ans = 0.0;

    for (int i = 1; i <= maxPts; i++)
    {

        ans += solve(n, k, pt + i, maxPts) / maxPts;
    }

    return ans;
}

double new21Game(int n, int k, int maxPts)
{
    return solve(n, k, 0, maxPts);
}

// rec + mem
double solveMem(int n, int k, int pt, int maxPts, vector<double> &dp)
{

    if (pt >= k && pt <= n)
        return 1.0;

    if (pt >= k && pt > n)
        return 0.0;

    if (dp[pt] != -1)
        return dp[pt];

    double ans = 0.0;

    for (int i = 1; i <= maxPts; i++)
    {
        ans += solveMem(n, k, pt + i, maxPts, dp) / maxPts;
    }

    return dp[pt] = ans;
}

double new21Game(int n, int k, int maxPts)
{
    vector<double> dp(k + maxPts, -1);
    return solveMem(n, k, 0, maxPts, dp);
}

// tabulation
double new21Game(int n, int k, int maxPts)
{
    vector<double> dp(k + maxPts + 1, 0);

    for (int i = k; i <= n; i++)
        dp[i] = 1.0;

    for (int pt = k - 1; pt >= 0; pt--)
    {
        double ans = 0.0;

        for (int i = 1; i <= maxPts; i++)
        {
            ans += dp[pt + i] / maxPts;
        }

        dp[pt] = ans;
    }

    return dp[0];
}

// leetcode soln
double new21Game(int n, int k, int maxPts)
{
    if (k == 0 || n >= k + maxPts)
        return 1.0;

    vector<double> dp(n + 1);
    dp[0] = 1.0;

    double currsum = 1.0;
    double ans = 0.0;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = currsum / maxPts;
        if (i < k)
        {
            currsum += dp[i];
        }
        else
            ans += dp[i];

        if (i >= maxPts)
        {
            currsum -= dp[i - maxPts];
        }
    }
    return ans;
}