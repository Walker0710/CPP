#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> bitCnt(32, 0);
    int curr = 0;
    int l = 0;
    int mini = INT_MAX;

    for (int r = 0; r < n; r++)
    {
        curr |= nums[r];

        for (int i = 0; i < 32; i++)
        {
            if (nums[r] & (1 << i))
            {
                bitCnt[i]++;
            }
        }

        while (l <= r && curr >= k)
        {
            mini = min(mini, r - l + 1);
            int updt = 0;
            
            for (int i = 0; i < 32; i++)
            {
                if (nums[l] & (1 << i))
                {
                    bitCnt[i]--;
                }

                if (bitCnt[i] > 0)
                {
                    updt |= (1 << i);
                }
            }
            curr = updt;
            l++;
        }
    }

    return mini == INT_MAX ? -1 : mini;
}