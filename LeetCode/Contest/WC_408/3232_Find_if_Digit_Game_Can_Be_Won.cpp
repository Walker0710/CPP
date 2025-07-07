#include <bits/stdc++.h>

using namespace std;

// << ,

bool canAliceWin(vector<int> &nums)
{
    int single = 0;
    int doub = 0;
    int total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= 9)
            single += nums[i];

        else if (nums[i] > 9 && nums[i] <= 99)
        {
            doub += nums[i];
        }

        total += nums[i];
    }

    if (single > total - single)
        return true;

    if (doub > total - doub)
        return true;

    return false;
}