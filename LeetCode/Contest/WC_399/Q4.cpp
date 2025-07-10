#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
    return 0;
    
    if (n == 1)
    return max(0, nums[0]);

    int prev2 = max(0, nums[0]);
    int prev1 = max(prev2, nums[1]);

    for (int i = 2; i < n; i++)
    {
        int current = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
{
    int MOD = 1e9 + 7;
    long long ans = 0;

    for (auto query : queries)
    {
        int pos = query[0];
        int xi = query[1];

        nums[pos] = xi;

        ans += solve(nums);
        ans %= MOD;
    }

    return ans;
}