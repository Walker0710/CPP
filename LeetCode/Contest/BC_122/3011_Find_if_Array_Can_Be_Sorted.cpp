#include <bits/stdc++.h>

using namespace std;

// << ,

bool canSortArray(vector<int> &nums)
{
    int n = nums.size();

    auto pop = [](int x)
    {
        return __builtin_popcount(x);
    };

    int i = 0;

    while (i < n)
    {
        int j = i;

        while (j + 1 < n && pop(nums[j]) == pop(nums[j + 1]))
        {
            j++;
        }

        sort(nums.begin() + i, nums.begin() + j + 1);

        i = j + 1;
    }

    for (int k = 1; k < n; ++k)
    {
        if (nums[k] < nums[k - 1])
        return false;
    }

    return true;
}