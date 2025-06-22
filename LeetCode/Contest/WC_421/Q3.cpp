#include <bits/stdc++.h>

using namespace std;

// << ,

int M = 1e9 + 7;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int solve(int index, int one, int two, vector<int> &nums, vector<vector<vector<int>>> &dp)
{
    if (index >= nums.size())
    {
        return (one != 0 && two != 0 && one == two) ? 1 : 0;
    }

    if (dp[index][one][two] != -1)
    {
        return dp[index][one][two];
    }

    int result = 0;

    result = (result + solve(index + 1, (one == 0) ? nums[index] : gcd(one, nums[index]), two, nums, dp)) % M;

    result = (result + solve(index + 1, one, (two == 0) ? nums[index] : gcd(two, nums[index]), nums, dp)) % M;

    result = (result + solve(index + 1, one, two, nums, dp)) % M;

    return dp[index][one][two] = result;
}

int subsequencePairCount(vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end());
    vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(maxi + 1, vector<int>(maxi + 1, -1)));
    return solve(0, 0, 0, nums, dp);
}