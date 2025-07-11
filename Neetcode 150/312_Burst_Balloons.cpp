#include <bits/stdc++.h>

using namespace std;

// << ,

// rec only

int dfs(vector<int> &nums)
{
    if (nums.size() == 2)
        return 0;

    int maxCoins = 0;

    for (int i = 1; i < nums.size() - 1; i++)
    {
        int coins = nums[i - 1] * nums[i] * nums[i + 1];

        vector<int> newNums = nums;
        newNums.erase(newNums.begin() + i);

        coins += dfs(newNums);

        maxCoins = max(maxCoins, coins);
    }

    return maxCoins;
}

int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return dfs(nums);
}

// rec + mem

int dp[305][305];

int solve(vector<int> &nums, int i, int j)
{
    int maxi = 0;
    
    if (dp[i][j] != -1)
    return dp[i][j];
    
    for (int k = i + 1; k <= j - 1; k++)
    {
        int c = nums[i] * nums[j] * nums[k] + solve(nums, i, k) + solve(nums, k, j);
        maxi = max(maxi, c);
    }
    
    return dp[i][j] = maxi;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
 
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    memset(dp, -1, sizeof(dp));
 
    return solve(nums, 0, nums.size() - 1);
}