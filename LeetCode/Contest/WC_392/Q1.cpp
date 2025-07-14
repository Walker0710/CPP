#include <bits/stdc++.h>

using namespace std;

// << ,

int longestMonotonicSubarray(vector<int> &nums)
{
    int n = nums.size();

    int maxInc = 1, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        maxInc = max(maxInc, cnt);
    }

    int maxDec = 1;
    cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        maxDec = max(maxDec, cnt);
    }

    return max(maxInc, maxDec);
}