#include <bits/stdc++.h>

using namespace std;

// << ,

long long solve(int index, int groupIndex, int groupSum, int groupCost, vector<int> &nums, vector<int> &cost, int k)
{
    if (index == nums.size())
    {
        return (groupSum + k * groupIndex) * groupCost;
    }

    long long extend = solve(index + 1, groupIndex, groupSum + nums[index], groupCost + cost[index], nums, cost, k);

    long long endGroupCost = (groupSum + k * groupIndex) * groupCost;
    long long startNew = endGroupCost + solve(index + 1, groupIndex + 1, nums[index], cost[index], nums, cost, k);

    return min(extend, startNew);
}

long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
{
    return solve(1, 1, nums[0], cost[0], nums, cost, k);
}

long long solve(int index, int groupIndex, int prefixSum, vector<int> &nums, vector<int> &cost, int k, unordered_map<string, long long> &dp)
{
    if (index == nums.size())
        return 0;

    string key = to_string(index) + "|" + to_string(groupIndex) + "|" + to_string(prefixSum);

    if (dp.count(key))
        return dp[key];

    long long res = LLONG_MAX;
    long long sumNums = 0, sumCost = 0;

    for (int i = index; i < nums.size(); ++i)
    {
        sumNums += nums[i];
        sumCost += cost[i];

        long long currCost = (prefixSum + sumNums + k * groupIndex) * sumCost;

        long long next = solve(i + 1, groupIndex + 1, prefixSum + sumNums, nums, cost, k, dp);

        res = min(res, currCost + next);
    }

    return dp[key] = res;
}

long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
{
    unordered_map<string, long long> dp;
    return solve(0, 1, 0, nums, cost, k, dp);
}

long long solve(int start, int end, int k, vector<long long> &prefixNums, vector<long long> &prefixCosts, vector<vector<long long>> &dp)
{
    int n = prefixNums.size();
    if (end == n)
    {
        if (start == n)
            return 0;
        return LLONG_MAX;
    }

    if (dp[start][end] != -1)
        return dp[start][end];

    long long currentNumsSum = prefixNums[end];
    long long currentCostSum = prefixCosts[n - 1];

    if (start != 0)
    {
        currentNumsSum = prefixNums[end] - prefixNums[start - 1];
        currentCostSum = prefixCosts[n - 1] - prefixCosts[start - 1];
    }

    long long currentSubarrayCost = (currentNumsSum + k) * currentCostSum;

    long long costIfCutHere = solve(end + 1, end + 1, k, prefixNums, prefixCosts, dp);
    if (costIfCutHere != LLONG_MAX)
        costIfCutHere += currentSubarrayCost;

    long long costIfExtend = solve(start, end + 1, k, prefixNums, prefixCosts, dp);

    return dp[start][end] = min(costIfCutHere, costIfExtend);
}

long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
{
    int n = nums.size();
    vector<long long> prefixNums(n), prefixCosts(n);

    prefixNums[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixNums[i] = prefixNums[i - 1] + nums[i];
    }

    prefixCosts[0] = cost[0];
    for (int i = 1; i < n; i++)
    {
        prefixCosts[i] = prefixCosts[i - 1] + cost[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    return solve(0, 0, k, prefixNums, prefixCosts, dp);
}