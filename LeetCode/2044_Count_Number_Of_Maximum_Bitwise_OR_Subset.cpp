#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(vector<int> &nums, int maxi, int index, int curr)
{
    if (index == nums.size())
    {
        return curr == maxi ? 1 : 0;
    }

    if (curr == maxi)
    {
        return 1 << (nums.size() - index);
    }

    return solve(nums, maxi, index + 1, curr | nums[index]) + solve(nums, maxi, index + 1, curr);
}

int countMaxOrSubsets(vector<int> &nums)
{
    int maxi = 0;

    for (int num : nums)
    {
        maxi |= num;
    }

    return solve(nums, maxi, 0, 0);
}