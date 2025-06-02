#include <bits/stdc++.h>

using namespace std;

// << ,

bool isSorted(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(vector<int> &nums)
{
    int operation = 0;

    while (!isSorted(nums))
    {
        int minsum = nums[0] + nums[1];
        int index = 0;

        for (int i = 1; i < nums.size() - 1; i++)
        {
            int currsum = nums[i] + nums[i + 1];
            if (currsum < minsum)
            {
                minsum = currsum;
                index = i;
            }
        }

        nums[index] = minsum;

        nums.erase(nums.begin() + index + 1);
        operation++;
    }

    return operation;
}