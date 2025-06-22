#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();

    for (int i = 0; i + 2 * k <= n; i++)
    {
        bool one = true;
        bool two = true;

        for (int j = 0; j < k - 1; j++)
        {
            if (nums[j + i] >= nums[j + i + 1])
            {
                one = false;
                break;
            }
        }

        for (int j = 0; j < k - 1; j++)
        {
            if (nums[j + i + k] >= nums[j + i + 1 + k])
            {
                two = false;
                break;
            }
        }

        if (one && two)
            return true;
    }

    return false;
}