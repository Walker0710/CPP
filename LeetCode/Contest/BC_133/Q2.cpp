#include <bits/stdc++.h>

using namespace std;

// << ,

int minOperations(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0 && i + 2 < n)
        {
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ans++;
        }
    }

    int sum = 0;

    for (auto &x : nums)
    {
        sum += x;
    }

    if (sum == n)
        return ans;

    return -1;
}