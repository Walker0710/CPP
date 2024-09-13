#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

int solve(int ind, int prev, vector<vector<int>> &dp, vector<vector<int>> &clips, int time)
{
    if (ind == clips.size())
    {
        if (clips[prev][1] >= time)
        return 0;
        
        return 1e9;
    }

    if (clips[prev][1] >= time)
    return 0;

    if (dp[ind][prev] != -1)
    return dp[ind][prev];

    int take = 1e9;

    if (clips[ind][0] <= clips[prev][1])
    {
        take = 1 + solve(ind + 1, ind, dp, clips, time);
    }

    int notTake = solve(ind + 1, prev, dp, clips, time);
    return dp[ind][prev] = min(take, notTake);
}

int videoStitching(vector<vector<int>> &clips, int time)
{
    int n = clips.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    sort(clips.begin(), clips.end());
    int mini = 1e9;
 
    for (int i = 0; i < n; i++)
    {
        if (clips[i][0] == 0)
        mini = min(mini, 1 + solve(i + 1, i, dp, clips, time));
    }

    if (mini == 1e9)
    return -1;

    return mini;
}