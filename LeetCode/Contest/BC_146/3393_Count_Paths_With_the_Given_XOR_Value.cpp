#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int j, int curr_xor, int n, int m, unordered_map<long long, int> &memo, int mod, vector<vector<int>> &grid, int k)
{
    if (i == n - 1 && j == m - 1)
        return (curr_xor ^ grid[i][j]) == k ? 1 : 0;

    if (i >= n || j >= m)
        return 0;

    // this will create a unique hash key
    long long key = ((long long)i << 40) | ((long long)j << 20) | curr_xor;
    
    if (memo.count(key))
        return memo[key];

    int down = solve(i + 1, j, curr_xor ^ grid[i][j], n, m, memo, mod, grid, k);
    int right = solve(i, j + 1, curr_xor ^ grid[i][j], n, m, memo, mod, grid, k);
    
    memo[key] = (down + right) % mod;

    return memo[key];
}

int countPathsWithXorValue(vector<vector<int>> &grid, int k)
{
    int mod = 1e9 + 7;
    int n = grid.size();
    int m = grid[0].size();
    unordered_map<long long, int> memo;

    return solve(0, 0, 0, n, m, memo, mod, grid, k);
}