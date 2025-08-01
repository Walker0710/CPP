#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// only rec
int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
{

    if (index >= nums1.size())
        return 0;

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // main point
    if (swapped)
        swap(prev1, prev2);

    // no swap wla case
    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solve(nums1, nums2, index + 1, 0);

    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));

    return ans;
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    return solve(nums1, nums2, 1, swapped);
}

// rec + mem
int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> dp)
{

    if (index >= nums1.size())
        return 0;

    if (dp[index][swapped] != -1)
        return dp[index][swapped];

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // main point
    if (swapped)
        swap(prev1, prev2);

    // no swap wla case
    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solveMem(nums1, nums2, index + 1, 0, dp);

    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp));

    return dp[index][swapped] = ans;
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;

    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));
    return solveMem(nums1, nums2, 1, swapped, dp);
}

// Tabulation
int solveTab(vector<int> &nums1, vector<int> &nums2)
{

    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n-1; index >= 0; index--)
    {

        for (int swapped = 1; swapped >= 0; swapped--)
        {

            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            // main point
            if (swapped)
                swap(prev1, prev2);

            // no swap wla case
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = dp[index + 1][0];

            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + dp[index + 1][1]);

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;

    return solveTab(nums1, nums2);
}

//space opt
int solveOpt(vector<int> &nums1, vector<int> &nums2) {

    int n = nums1.size();
    int swapO = 0;
    int noswapO = 0;
    int currswapO = 0;
    int currnoswapO = 0;

    for (int index = n-1; index >= 0; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            // main point
            if (swapped)
                swap(prev1, prev2);

            // no swap wla case
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = noswapO;

            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + swapO);
            
            if(swapped)
            currswapO = ans;

            else
            currnoswapO = ans;
        }

        swapO = currswapO;
        noswapO = currnoswapO;
    } 

    return min(swapO, noswapO);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;

    return solveOpt(nums1, nums2);
}
