#include <bits/stdc++.h>

using namespace std;

// << ,

// Recursive function to solve the problem
int solve(int mask, int x, int K, vector<int> &nums, int n)
{
    // If all tasks are completed, return 0
    if (mask == (1 << n) - 1)
    {
        return 0;
    }

    int mini = INT_MAX;

    // Explore all tasks
    for (int i = 0; i < n; i++)
    {
        // If task i is not completed (not in the mask)
        if (!(mask & (1 << i)))
        {
            // Calculate time required to complete task i
            int time = (nums[i] + x - 1) / x;

            // Recursively compute the minimum time for the next task
            mini = min(mini, time + solve(mask | (1 << i), x + K, K, nums, n));
        }
    }

    return mini;
}

// Function to find the minimum time to complete all tasks
int findMinimumTime(vector<int> &strength, int K)
{
    int n = strength.size();            // Number of tasks
    int x = 1;                          // Initial value of x
    return solve(0, x, K, strength, n); // Start with no tasks completed
}





int recur(vector<vector<int>> &values, int idx, int mask_row, map<pair<int, int>, int> &dp)
{
    int n = values.size();

    if (idx == n)
        return 0;

    if (dp.find({idx, mask_row}) != dp.end())
        return dp[{idx, mask_row}];

    int ans = 0;
    int row = values[idx][1];

    if ((1 << row) & mask_row)
        ans += recur(values, idx + 1, mask_row, dp);

    else
    {
        int j = idx;
    
        while (j < n and values[idx][0] == values[j][0])
            j++;

        int ans1 = values[idx][0] + recur(values, j, mask_row | (1 << row), dp);
        int ans2 = recur(values, idx + 1, mask_row, dp);

        ans = max(ans1, ans2);
    }

    return dp[{idx, mask_row}] = ans;
}

int maxScore(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> values;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            values.push_back({grid[i][j], i, j});
        }
    }

    sort(values.begin(), values.end(), greater<vector<int>>());
    map<pair<int, int>, int> dp;

    return recur(values, 0, 0, dp);
}








int dp[1 << 15][15];
vector<int> a;
int n;

int find(int mask, int pre)
{
    if (mask == (1 << n) - 1)
    {
        return abs(pre - a[0]);
    }

    if (dp[mask][pre] != -1)
    return dp[mask][pre];

    int ans = 1e8;
    
    for (int j = 0; j < n; j++)
    {
        if ((mask >> j) & 1)
        continue;
        
        ans = min(ans, abs(pre - a[j]) + find(mask | (1 << j), j));
    }

    return dp[mask][pre] = ans;
}

void buildPath(int mask, int pre, vector<int> &res)
{
    if (mask == (1 << n) - 1)
    return;

    int ans = 1e8, next = -1;

    for (int j = 0; j < n; j++)
    {
        if ((mask >> j) & 1)
        continue;
        
        int nans = abs(pre - a[j]) + find(mask | (1 << j), j);
        
        if (nans < ans)
        {
            ans = nans;
            next = j;
        }
    }

    res.push_back(next);
    
    buildPath(mask | (1 << next), next, res);
}

vector<int> findPermutation(vector<int> &input)
{
    a = input;
    n = a.size();

    memset(dp, -1, sizeof(dp));

    find(1, 0);

    vector<int> res = {0};
    buildPath(1, 0, res);

    return res;
}




class Solution {
public:
    unordered_map<long long, int> mp;

    int solve(int ind, int mask, bool flag, string &s, int k) {

        long long key = (1LL * ind << 27) | (1LL * mask << 1) | flag;

        if (mp.count(key)) {
            return mp[key];
        }

        if (ind == s.size()) {
            return 0;
        }

        int charIndex = s[ind] - 'a';
        int newMask = mask | (1 << charIndex);
        
        int uniqueCount = __builtin_popcount(newMask);

        int res;

        if (uniqueCount > k) {
            res = 1 + solve(ind + 1, 1 << charIndex, flag, s, k);
        } 
        
        else {
            res = solve(ind + 1, newMask, flag, s, k);
        }

        if (flag) {
        
            for (int ch = 0; ch < 26; ++ch) {
        
                if (ch == charIndex) 
                continue;

                int changedMask = mask | (1 << ch);
                int changedCount = __builtin_popcount(changedMask);

                if (changedCount > k) {
                    res = max(res, 1 + solve(ind + 1, 1 << ch, false, s, k));
                }
                
                else {
                    res = max(res, solve(ind + 1, changedMask, false, s, k));
                }
            }
        }

        return mp[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return solve(0, 0, true, s, k) + 1;
    }
};
