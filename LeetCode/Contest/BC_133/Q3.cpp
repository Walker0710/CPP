#include <bits/stdc++.h>

using namespace std;

// << ,

int minOperations(vector<int> &nums)
{
    int cnt = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0 && cnt % 2 == 0)
        {
            cnt++;
        }

        else if (nums[i] == 1 && cnt % 2 == 1)
        {
            cnt++;
        }
    }

    return cnt;
}