#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// rec only
int solve(vector<int> &nums, int index)
{

    if (index >= nums.size() - 1)
        return 0;

    int ans = INT_MAX;

    for (int i = 1; i <= nums[index]; i++)
    {

        if (i + index < nums.size())
        {

            int yo = solve(nums, i + index);

            if (yo != INT_MAX)
                ans = min(ans, 1 + yo);
        }
    }

    return ans;
}

int jump(vector<int> &nums)
{

    return solve(nums, 0);
}

// rec + mem
int solveMem(vector<int> &nums, int index, vector<int> &dp)
{

    if (index >= nums.size() - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int ans = INT_MAX;

    for (int i = 1; i <= nums[index]; i++)
    {

        if (i + index < nums.size())
        {

            int yo = solveMem(nums, i + index, dp);

            if (yo != INT_MAX)
                ans = min(ans, 1 + yo);
        }
    }

    return dp[index] = ans;
}

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return solveMem(nums, 0, dp);
}

// tabulation
int solveTab(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, 0);

    for (int index = nums.size()-1; index>=0; index--)
    {
        int ans = INT_MAX;

        for (int i = 1; i <= nums[index]; i++)
        {
            if (i + index < nums.size())
            {
                int yo = dp[i + index];

                if (yo != INT_MAX)
                    ans = min(ans, 1 + yo);
            }
        }

        if(ans != INT_MAX)
        dp[index] = ans;
    }

    return dp[0];
}

int jump(vector<int> &nums)
{

    return solveTab(nums);
}
