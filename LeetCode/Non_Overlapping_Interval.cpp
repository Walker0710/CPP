#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
int solve(vector<vector<int>> &intervals, int prev, int curr)
{

    if (curr >= intervals.size())
        return 0;

    int ans = 0;

    if (intervals[prev][0] == intervals[curr][0])
    {
        ans = 1 + solve(intervals, prev, curr + 1);
    }

    else if (intervals[prev][1] > intervals[curr][0])
    {
        ans = 1 + min(solve(intervals, prev, curr + 1), solve(intervals, curr, curr + 1));
    }

    else
    {
        ans = solve(intervals, curr, curr + 1);
    }

    return ans;
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    return solve(intervals, 0, 1);
}

// rec + mem
int solveMem(vector<vector<int>> &intervals, int prev, int curr, vector<vector<int>> &dp)
{

    if (curr >= intervals.size())
        return 0;

    if (dp[prev][curr] != -1)
        return dp[prev][curr];

    int ans = 0;

    if (intervals[prev][0] == intervals[curr][0])
    {
        ans = 1 + solveMem(intervals, prev, curr + 1, dp);
    }

    else if (intervals[prev][1] > intervals[curr][0])
    {
        ans = 1 + min(solveMem(intervals, prev, curr + 1, dp), solveMem(intervals, curr, curr + 1, dp));
    }

    else
    {
        ans = solveMem(intervals, curr, curr + 1, dp);
    }

    return dp[prev][curr] = ans;
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> dp(intervals.size() + 1, vector<int>(intervals.size() + 1, -1));
    return solveMem(intervals, 0, 1, dp);
}

// tabulation
bool customComparator(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end(), customComparator);
    vector<vector<int>> dp(intervals.size() + 1, vector<int>(intervals.size() + 1, 0));

    for (int prev = intervals.size() - 1; prev >= 0; prev--)
    {
        for (int curr = intervals.size() - 1; curr >= 1; curr--)
        {
            int ans = 0;

            if (intervals[prev][0] == intervals[curr][0])
            {
                ans = 1 + dp[prev][curr + 1];
            }

            else if (intervals[prev][1] > intervals[curr][0])
            {
                ans = 1 + max(dp[prev][curr + 1], dp[curr][curr + 1]);
            }

            else
            {
                ans = dp[curr][curr + 1];
            }

            dp[prev][curr] = ans;
        }
    }

    return dp[0][1];
}

//leetcode
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 1)
    {
        return 0;
    }

    int ans = -1;
    sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b)
         { return a[1] < b[1]; });

    vector<int> prev = intervals[0];

    for (auto it : intervals)
    {
        if (it[0] < prev[1])
        {
            ans++;
        }
        else
        {
            prev = it;
        }
    }
    return ans;
}
