#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int ind, vector<vector<int>> &grid, map<pair<int, int>, int> &mp, int prev, vector<vector<int>> &dp) {
    if(ind >= grid[0].size()) {
        return 0;
    }

    if(dp[ind][prev] != -1)
    return dp[ind][prev]; 

    int ans = INT_MAX;

    for(int i = 0; i<=9; i++) {
        if(i != prev) {
            ans = min(ans, (int)grid.size() - mp[{ind, i}] + solve(ind+1, grid, mp, i, dp));
        }
    }

    return dp[ind][prev] = ans;
}

int minimumOperations(vector<vector<int>> &grid)
{
    map<pair<int, int>, int> mp;

    for(int i = 0; i<grid[0].size(); i++) {
        for(int j = 0; j<grid.size(); j++) {
            mp[{i, grid[j][i]}]++;
        }
    }

    vector<vector<int>> dp(grid[0].size() + 1, vector<int> (11, -1));

    return solve(0, grid, mp, 10, dp);
}