#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[5001][51];

int helper(int ind, int prev, int n, vector<int> &nums, int k)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev][k] != -1)
        return dp[ind][prev][k];

    int maxi = 0;

    if (prev == 500 || (nums[ind] == nums[prev]))
    {
        maxi = max(maxi, 1 + helper(ind + 1, ind, n, nums, k));
        maxi = max(maxi, helper(ind + 1, prev, n, nums, k));
    }

    for (int i = ind; i < n; i++)
    {
    }

    return dp[ind][prev][k] = maxi;
}

int maximumLength(vector<int> &nums, int k)
{
    int n = nums.size();
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] % n;
    }

    return helper(0, 500, n, nums, k);
}



int dp[5001][2][51];

int solve(int i, int count, bool same, vector<int> &nums, unordered_map<int, vector<int>> &mp)
{
    if (i >= nums.size())
    return 0;
    
    if (dp[i][same][count] != -1)
    return dp[i][same][count];

    int take = 0, notake = 0;
    vector<int> &v = mp[nums[i]];

    int ind = upper_bound(v.begin(), v.end(), i) - v.begin();

    if (ind == v.size())
    take = 1;
    
    else
    take = 1 + solve(v[ind], count, true, nums, mp);

    if (count > 0)
    take = max(take, 1 + solve(i + 1, count - 1, false, nums, mp));
    
    if (same == false)
    notake = solve(i + 1, count, false, nums, mp);

    return dp[i][same][count] = max(take, notake);
}

int maximumLength(vector<int> &nums, int k)
{
    memset(dp, -1, sizeof(dp));
    unordered_map<int, vector<int>> mp;
 
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i);
    }

    return solve(0, k, false, nums, mp);
}