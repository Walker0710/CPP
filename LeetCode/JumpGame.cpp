#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// only rec
bool solve(vector<int> &nums, int index)
{

    if (index >= nums.size() - 1)
        return true;

    bool yo = false;

    for (int i = 1; i <= nums[index]; i++)
    {

        if (i + index < nums.size())
            yo = solve(nums, i + index);

        if (yo == true)
            break;
    }

    return yo & true;
}

bool canJump(vector<int> &nums)
{

    return solve(nums, 0);
}

// rec + mem
bool solveMem(vector<int> &nums, int index, vector<int> &dp)
{

    if (index >= nums.size() - 1)
        return true;

    if (dp[index] != -1)
        return dp[index];

    bool yo = false;

    for (int i = 1; i <= nums[index]; i++)
    {

        if (i + index < nums.size())
            yo = solveMem(nums, i + index, dp);

        if (yo == true)
            break;
    }

    return dp[index] = yo & true;
}

bool canJump(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return solveMem(nums, 0, dp);
}

// Tabulation
int solveTab(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, 0);

    for (int index = nums.size() - 1; index >= 0; index--)
    {
        bool yo = false;

        for (int i = 1; i <= nums[index]; i++)
        {
            if (i + index < nums.size())
                yo = dp[i + index];

            if (yo == true)
                break;
        }

        dp[index] = yo;
    }

    return dp[0];
}

bool canJump(vector<int> &nums)
{
    return solveTab(nums);
}
