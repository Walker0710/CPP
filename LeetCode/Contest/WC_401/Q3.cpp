#include <bits/stdc++.h>

using namespace std;

// << ,

#define ll long long
int dp[2001][4000];

int find(int pos, int sum, vector<int> &nums)
{
    if (pos == nums.size())
        return 0;

    int ans = -1;

    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    if (nums[pos] > sum)
    {
        ans = max(ans, nums[pos] + find(pos + 1, sum + nums[pos], nums));
        ans = max(ans, find(pos + 1, sum, nums));
    }

    else
        ans = max(ans, find(pos + 1, sum, nums));

    return dp[pos][sum] = ans;
}

int maxTotalReward(vector<int> &rv)
{
    vector<int> nums;
    unordered_set<int> s;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < rv.size(); ++i)
        s.insert(rv[i]);

    for (auto i = s.begin(); i != s.end(); ++i)
        nums.push_back(*i);

    sort(nums.begin(), nums.end());

    int ans = find(0, 0, nums);
    return ans;
}




int solve(int i, int sum, vector<int> &rewardValues, vector<vector<int>> &dp)
{
    if (i == rewardValues.size())
        return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int inc = INT_MIN;

    if (sum < rewardValues[i])
    {
        inc = rewardValues[i] + solve(i + 1, sum + rewardValues[i], rewardValues, dp);
    }

    int exc = solve(i + 1, sum, rewardValues, dp);

    return max(inc, exc);
}

int maxTotalReward(vector<int> &rewardValues)
{
    vector<vector<int>> dp(2001, vector<int>(4000001, -1));
    sort(rewardValues.begin(), rewardValues.end());
    return solve(0, 0, rewardValues, dp);
}