#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

// brute force
int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
{

    int ans = 0;
    int n = nums.size();

    for (int i = 0; i + firstLen <= n; i++)
    {
        for (int j = i + firstLen + 1; j + secondLen <= n; j++)
        {

            int sum = accumulate(nums.begin() + i, nums.begin() + i + firstLen, 0) + accumulate(nums.begin() + j, nums.begin() + j + secondLen, 0);
            ans = max(ans, sum);
        }
    }

    return ans;
}

// dp
int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
{

    int ans = 0;
    int n = nums.size();
    int sum1 = accumulate(nums.begin(), nums.begin() + firstLen, 0);
    int sum2 = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);

    for (int i = 0; i + firstLen <= n; i++)
    {

        if (i != 0)
        {

            int sumF = sum1 - nums[i - 1] + nums[i + firstLen - 1];

            if (sumF > sum1)
                sum1 = sumF;
        }

        for (int j = i + firstLen + 1; j + secondLen <= n; j++)
        {
            int sumS = sum2 - nums[j - 1] + nums[j + secondLen - 1];

            if (sumS > sum2)
                sum2 = sumS;

            ans = max(ans, sum1 + sum2);
        }
    }
    return ans;
}

// rec
int dp[1010][2][2];

int solve(int index, vector<int> &nums, int firstLen, int secondLen, bool fs, bool sc, vector<int> &prefix)
{
    if (fs == 1 && sc == 1)
    {
        return 0;
    }

    if (dp[index][fs][sc] != -1)
        return dp[index][fs][sc];

    int ans = INT_MIN;

    if (fs == 0)
    {
        if (index + firstLen <= nums.size())
        {
            ans = max({ans, prefix[index + firstLen - 1] - (index > 0 ? prefix[index - 1] : 0) + solve(index + firstLen, nums, firstLen, secondLen, 1, sc, prefix), solve(index + 1, nums, firstLen, secondLen, fs, sc, prefix)});
        }
        else
        {
            return INT_MIN;
        }
    }

    if (sc == 0)
    {
        if (index + secondLen <= nums.size())
        {
            ans = max({ans, prefix[index + secondLen - 1] - (index > 0 ? prefix[index - 1] : 0) + solve(index + secondLen, nums, firstLen, secondLen, fs, 1, prefix), solve(index + 1, nums, firstLen, secondLen, fs, sc, prefix)});
        }
        else
        {
            return INT_MIN;
        }
    }
    return dp[index][fs][sc] = ans;
}

int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
{
    int pre = 0;
    vector<int> prefix;

    for (auto i : nums)
    {
        pre += i;
        prefix.push_back(pre);
    }

    memset(dp, -1, sizeof(dp));
    return solve(0, nums, firstLen, secondLen, 0, 0, prefix);
}
