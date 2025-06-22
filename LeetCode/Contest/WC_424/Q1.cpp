#include <bits/stdc++.h>

using namespace std;

// << ,

int countValidSelections(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 2;

    int l = 0;
    int r = 0;

    for (int i = 0; i < n; ++i)
    {
        r += nums[i];
    }

    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0)
        {
            if (l == r - l)
            {
                count += 2;
            }

            if (l + 1 == r - l || l == r - l + 1)
            {
                count++;
            }
        }

        else
        {
            l += nums[i];
        }
    }

    return count;
}