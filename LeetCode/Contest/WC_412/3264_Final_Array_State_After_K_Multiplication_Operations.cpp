#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    for (int i = 0; i < k; i++)
    {
        int mini = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < mini)
            {
                mini = nums[j];
                minIndex = j;
            }
        }

        nums[minIndex] = nums[minIndex] * multiplier;
    }

    return nums;
}