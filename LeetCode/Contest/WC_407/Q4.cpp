#include <bits/stdc++.h>

using namespace std;

// << ,

long long minimumOperations(vector<int> &nums, vector<int> &target)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        nums[i] = target[i] - nums[i];
    }

    long long prev = abs(nums[0]);

    for (int i = 1; i < n; i++)
    {
        long long curr;
        bool temp = (1ll * nums[i] * nums[i - 1]) > 0;

        if (temp)
        {
            if (abs(nums[i]) > abs(nums[i - 1]))
            {
                curr = prev + abs(nums[i] - nums[i - 1]);
            }

            else
            {
                curr = prev;
            }
        }

        else
        {
            curr = prev + abs(nums[i]);
        }
        prev = curr;
    }

    return prev;
}