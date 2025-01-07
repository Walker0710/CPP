#include <bits/stdc++.h>

using namespace std;

// << ,

// nlog(n), 1
int findDuplicate(vector<int> &nums)
{
    int left = 1;
    int right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int count = 0;

        for (int num : nums)
        {
            if (num <= mid)
            {
                count++;
            }
        }

        if (count > mid)
            right = mid;

        else
            left = mid + 1;
    }

    return left;
}

// most eff algo
//  O(n), O(1)

int findDuplicate(vector<int> &nums)
{

    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    while (slow != fast);

    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
