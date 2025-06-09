#include <bits/stdc++.h>

using namespace std;

// << ,

long long minMaxSubarraySum(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int MOD = 1e9 + 7;
    vector<vector<long long>> ncr(nums.size() + 1, vector<long long>(k + 1, 0));

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