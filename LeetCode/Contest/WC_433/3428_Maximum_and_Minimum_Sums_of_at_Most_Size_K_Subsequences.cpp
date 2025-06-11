#include <bits/stdc++.h>

using namespace std;

// << ,

void dfs(int index, vector<int> &nums, int k, int first, int last, long long &result, const int MOD)
{
    if (index == nums.size())
    {
        if (k >= 0 && first != -1)
        {
            result = (result + nums[first] + nums[last]) % MOD;
        }
        return;
    }

    if (first == -1)
    {
        // inc
        dfs(index + 1, nums, k - 1, index, index, result, MOD);

        // exc
        dfs(index + 1, nums, k, first, last, result, MOD);
    }

    else
    {
        // inc
        dfs(index + 1, nums, k - 1, first, index, result, MOD);

        // exc
        dfs(index + 1, nums, k, first, last, result, MOD);
    }
}

int minMaxSums(vector<int> &nums, int k)
{
    const int MOD = 1e9 + 7;
    long long result = 0;

    sort(nums.begin(), nums.end());

    dfs(0, nums, k, -1, -1, result, MOD);

    return result % MOD;
}








// Solved using combinatorial approach

int minMaxSums(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    int MOD = 1e9 + 7;
    vector<vector<int>> ncr(nums.size() + 1, vector<int>(k + 1, 0));

    ncr[0][0] = 1;
 
    for (int n = 1; n <= nums.size(); n++)
    {
        ncr[n][0] = 1;
 
        for (int r = 1; r <= k; r++)
            ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % MOD;
    }

    for (int n = 0; n < nums.size(); n++)
    {
        int numberOfSubsequences = 0;
 
        for (int r = 0; r <= k - 1; r++)
            if (n >= r)
                numberOfSubsequences = (numberOfSubsequences + ncr[n][r]) % MOD;
 
        ans = (ans + (long long)(nums[n] + nums[nums.size() - n - 1]) * numberOfSubsequences) % MOD;
    }
    return ans;
}