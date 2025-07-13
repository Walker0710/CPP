#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<unordered_map<int, int>>> dp;

int helper(vector<int> &nums, vector<int> &andValues, int ind, int j, int And)
{
    if (ind >= nums.size())
    {
        if (j >= andValues.size())
        return 0;
        
        else
        return 1e8;
    }
    
    else if (j >= andValues.size())
    return 1e8;

    if (dp[ind][j].count(And))
    return dp[ind][j][And];

    int inclu = 1e8;
    
    if ((And & nums[ind]) == andValues[j])
    {
        inclu = nums[ind] + helper(nums, andValues, ind + 1, j + 1, ((1 << 17) - 1));
    }
    
    int exclu = helper(nums, andValues, ind + 1, j, (And & nums[ind]));

    return dp[ind][j][And] = min(inclu, exclu);
}

int minimumValueSum(vector<int> &nums, vector<int> &andValues)
{
    int n = nums.size(), m = andValues.size();
    dp.resize(n, vector<unordered_map<int, int>>(m));

    int ans = helper(nums, andValues, 0, 0, ((1 << 17) - 1));

    if (ans == 1e8)
    return -1;
    
    return ans;
}