#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// olny rec
int solve(vector<int> &obstacles, int index, int lane)
{

    int n = obstacles.size() - 1;
    if (index == n - 1)
        return 0;

    if (lane < 1 || lane > 3)
        return 0;

    if (obstacles[index + 1] != lane)
    {

        return solve(obstacles, index + 1, lane);
    }

    else
    {

        int ans = INT_MAX;

        for (int i = 1; i <= 3; i++)
        {

            if (lane != i && obstacles[index] != i)
                ans = min(ans, 1 + solve(obstacles, index, i));
        }

        return ans;
    }
}

int minSideJumps(vector<int> &obstacles)
{

    return solve(obstacles, 0, 2);
}

// rec + mem
int solveMem(vector<int> &obstacles, int index, int lane, vector<vector<int>> &dp)
{

    int n = obstacles.size() - 1;
    if (index == n - 1)
        return 0;

    if (dp[lane][index] != -1)
        return dp[lane][index];

    if (obstacles[index + 1] != lane)
    {
        return solveMem(obstacles, index + 1, lane, dp);
    }

    else
    {

        int ans = INT_MAX;

        for (int i = 1; i <= 3; i++)
        {

            if (lane != i && obstacles[index] != i)
                ans = min(ans, 1 + solveMem(obstacles, index, i, dp));
        }

        dp[lane][index] = ans;
        return dp[lane][index];
    }
}

int minSideJumps(vector<int> &obstacles)
{

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
    return solveMem(obstacles, 0, 2, dp);
}

// tabulation
int solveTab(vector<int> &obstacles)
{ 
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9));
    dp[0][n - 1] = 0;
    dp[1][n - 1] = 0;
    dp[2][n - 1] = 0;
    dp[3][n - 1] = 0;

    for (int index = n - 2; index >= 0; index--)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (obstacles[index + 1] != lane)
                dp[lane][index] = dp[lane][index + 1];

            else
            {

                int ans = 1e9;

                for (int i = 1; i <= 3; i++)
                {

                    if (lane != i && obstacles[index] != i)
                        ans = min(ans, 1 + dp[i][index + 1]);
                }

                dp[lane][index] = ans;
            }
        }
    }

    return min(dp[2][0], min(1 + dp[3][0],1 + dp[1][0]));
}

int minSideJumps(vector<int> &obstacles)
{
    return solveTab(obstacles);
}

//space optimization
int solveOpt(vector<int> &obstacles)
{ 
    int n = obstacles.size();
    vector<int> curr(4, 1e9);
    vector<int> next(4, 1e9);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int index = n - 2; index >= 0; index--)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (obstacles[index + 1] != lane)
                curr[index] = next[index];

            else
            {
                int ans = 1e9;

                for (int i = 1; i <= 3; i++)
                {
                    if (lane != i && obstacles[index] != i)
                    ans = min(ans, 1 + next[i]);
                }
                curr[index] = ans;
            }
        }
        next = curr;
    }
    return min(curr[2], min(1 + curr[1],1 + curr[3]));
}

int minSideJumps(vector<int> &obstacles)
{
    return solveOpt(obstacles);
}

