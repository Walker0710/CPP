#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasTrailingZeros(vector<int> &nums)
{
    int zero = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        zero++;
    }

    return zero >= 2;
}