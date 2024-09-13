#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// only rec
bool solve2(vector<int> &nums, int index, int sum1, int sum2)
{

    if (index == nums.size() && sum1 == sum2)
    {

        return true;
    }

    else if (index == nums.size())
    {
        return false;
    }

    // adding element in sum1
    bool first = solve2(nums, index + 1, sum1 + nums[index], sum2);

    // adding element to sum2
    bool second = solve2(nums, index + 1, sum1, sum2 + nums[index]);

    return first || second;
}

bool canPartition(vector<int> &nums)
{

    return solve2(nums, 0, 0, 0);
}

// optimize approch
bool solveOptRec(vector<int> &nums, int index, int target)
{
    if (index >= nums.size())
        return false;

    if (target == 0)
        return true;

    // inc
    bool first = solveOptRec(nums, index + 1, target - nums[index]);

    // exc
    bool second = solveOptRec(nums, index + 1, target);

    return first || second;
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totSum = 0;

    for (int i = 0; i < n; i++)
        totSum += nums[i];

    if (totSum % 2)
        return false;

    int target = totSum / 2;

    return solveOptRec(nums, 0, target);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, 0), cur(k + 1, 0);
    prev[0] = cur[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += nums[i];
    if (totSum % 2)
        return false;

    int target = totSum / 2;
    return subsetSumToK(n, target, nums);
}
