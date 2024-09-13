#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
double solve(int a, int b)
{

    if (a <= 0 && b <= 0)
        return 0.5;

    if (b <= 0)
        return 0;

    if (a <= 0)
        return 1;

    double ans = 0;

    double first = 0.25 * solve(a - 100, b - 0);
    double second = 0.25 * solve(a - 75, b - 25);
    double third = 0.25 * solve(a - 50, b - 50);
    double fourth = 0.25 * solve(a - 25, b - 75);

    ans = first + second + third + fourth;

    return ans;
}

double soupServings(int n)
{
    return solve(n, n);
}

// rec + mem
double solveMem(int a, int b, vector<vector<double>> &dp)
{

    if (a <= 0 && b <= 0)
        return 0.5;

    if (b <= 0)
        return 0;

    if (a <= 0)
        return 1;

    if (dp[a][b] != -1.0)
        return dp[a][b];

    double ans = 0;

    double first = 0.25 * solveMem(a - 100, b - 0, dp);
    double second = 0.25 * solveMem(a - 75, b - 25, dp);
    double third = 0.25 * solveMem(a - 50, b - 50, dp);
    double fourth = 0.25 * solveMem(a - 25, b - 75, dp);

    ans = first + second + third + fourth;

    return dp[a][b] = ans;
}

double soupServings(int n)
{

    if (n > 4800)
        return 1.0;

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));
    return solveMem(n, n, dp);
}

// tabulation
double soupServings(int n)
{
    if (n > 4800)
        return 1;
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

    dp[0][0] = 0.5;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double x = 0.25 * dp[max(0, i - 100)][j];
            double y = 0.25 * dp[max(0, i - 75)][max(0, j - 25)];
            double z = 0.25 * dp[max(0, i - 50)][max(0, j - 50)];
            double w = 0.25 * dp[max(0, i - 25)][max(0, j - 75)];

            dp[i][j] = x + y + w + z;
        }
    }
    return dp[n][n];
}
