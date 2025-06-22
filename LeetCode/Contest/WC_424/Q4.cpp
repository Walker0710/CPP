#include <bits/stdc++.h>

using namespace std;

// << ,

bool isValidDifference(vector<int> nums, int maxDiff)
{

    int min_element = INT_MAX;
    int max_element = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    { // n
        if (nums[i] != -1 && (i && nums[i - 1] == -1 || (i != nums.size() - 1) && nums[i + 1] == -1))
        {
            min_element = min(min_element, nums[i]);
            max_element = max(max_element, nums[i]);
        }
    }

    int minValue = min_element + maxDiff;
    int maxValue = max_element - maxDiff;

    int flag1 = 1;
    int flag2 = 1;

    vector<int> copyNums = nums;
    for (int i = 0; i < copyNums.size(); i++)
    { 
        if (copyNums[i] == -1)
        { 
            if (
                (i == 0 || abs(copyNums[i - 1] - minValue) <= maxDiff) &&
                (i == (copyNums.size() - 1) || copyNums[i + 1] == -1 || abs(copyNums[i + 1] - minValue) <= maxDiff))
            {
                copyNums[i] = minValue;
            }
            else
            {
                copyNums[i] = maxValue;
            }
        }
    }

    for (int i = 0; i < copyNums.size() - 1; i++)
    {
        if (abs(copyNums[i] - copyNums[i + 1]) > maxDiff)
        {
            flag1 = 0;
        }
    }

    copyNums = nums;
    for (int i = 0; i < copyNums.size(); i++)
    { // n
        if (copyNums[i] == -1)
        {
            if (
                (i == 0 || abs(copyNums[i - 1] - maxValue) <= maxDiff) &&
                (i == (copyNums.size() - 1) || copyNums[i + 1] == -1 || abs(copyNums[i + 1] - maxValue) <= maxDiff))
            {
                copyNums[i] = maxValue;
            }
            else
            {
                copyNums[i] = minValue;
            }
        }
    }

    for (int i = 0; i < copyNums.size() - 1; i++)
    {
        if (abs(copyNums[i] - copyNums[i + 1]) > maxDiff)
        {
            flag2 = 0;
        }
    }

    return flag1 || flag2;
}

int minDifference(vector<int> &nums)
{
    int missingCount = 0;

    for (int x : nums)
        if (x == -1)
            missingCount++;

    if (missingCount == 0)
    {
        int maxDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i + 1]));
        }
        return maxDiff;
    }
    else if (missingCount == nums.size())
        return 0;

    int low = 0;
    int high = 1000000005;
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isValidDifference(nums, mid))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}