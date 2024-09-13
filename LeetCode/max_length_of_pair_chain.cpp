#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

// only rec
int solve(vector<vector<int>> &pairs, int prev, int curr)
{

    if (curr >= pairs.size())
        return 0;

    int ans = 0;
    int inc = 0;
    int exc = 0;

    if (pairs[prev][1] < pairs[curr][0])
    {

        inc = 1 + solve(pairs, curr, curr + 1);
        exc = 0 + solve(pairs, prev, curr + 1);

        ans = max(inc, exc);
    }

    else
    {
        inc = solve(pairs, prev, curr + 1);
        exc = solve(pairs, curr, curr + 1);

        ans = max(inc, exc);
    }

    return ans;
}

int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    return 1 + solve(pairs, 0, 1);
}

// rec + mem
int solveMem(vector<vector<int>> &pairs, int prev, int curr, vector<vector<int>> &dp)
{

    if (curr >= pairs.size())
        return 0;

    if (dp[prev][curr] != -1)
        return dp[prev][curr];

    int inc = 0;
    int exc = 0;

    if (pairs[prev][1] < pairs[curr][0])
    {
        inc = 1 + solveMem(pairs, curr, curr + 1, dp);
        exc = 0 + solveMem(pairs, prev, curr + 1, dp);
    }

    else
    {
        inc = solveMem(pairs, prev, curr + 1, dp);
        exc = solveMem(pairs, curr, curr + 1, dp);
    }

    return dp[prev][curr] = max(inc, exc);
}

int findLongestChain(vector<vector<int>> &pairs)
{
    vector<vector<int>> dp(pairs.size() + 1, vector<int>(pairs.size() + 1, -1));
    sort(pairs.begin(), pairs.end());
    return 1 + solveMem(pairs, 0, 1, dp);
}

// tabulation
int findLongestChain(vector<vector<int>> &pairs)
{
    vector<vector<int>> dp(pairs.size() + 1, vector<int>(pairs.size() + 1, 0));
    sort(pairs.begin(), pairs.end());

    for (int prev = pairs.size() - 1; prev >= 0; prev--)
    {
        for (int curr = pairs.size() - 1; curr >= 1; curr--)
        {
            int inc = 0;
            int exc = 0;

            if (pairs[prev][1] < pairs[curr][0])
            {
                inc = 1 + dp[curr][curr + 1];
                exc = 0 + dp[prev][curr + 1];
            }

            else
            {
                inc = dp[prev][curr + 1];
                exc = dp[curr][curr + 1];
            }

            dp[prev][curr] = max(inc, exc);
        }
    }
    return dp[0][1]; 
}
