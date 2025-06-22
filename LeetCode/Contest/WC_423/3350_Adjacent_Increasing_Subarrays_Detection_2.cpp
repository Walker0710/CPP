#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    if (2 * k > n)
        return false;

    for (int i = 0; i + 2 * k <= n; i++)
    {
        bool one = true, two = true;

        for (int j = 0; j < k - 1; j++)
        {
            if (nums[i + j] >= nums[i + j + 1])
            {
                one = false;
                break;
            }
        }

        for (int j = 0; j < k - 1; j++)
        {
            if (nums[i + k + j] >= nums[i + k + j + 1])
            {
                two = false;
                break;
            }
        }

        if (one && two)
            return true;
    }

    return false;
}

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int a = 0; a + 2 * k <= n; ++a)
    {
        int b = a + k;
        bool valid = true;
        for (int i = 1; i < k; ++i)
        {
            if (nums[a + i] <= nums[a + i - 1] || nums[b + i] <= nums[b + i - 1])
            {
                valid = false;
                break;
            }
        }
        if (valid)
            return true;
    }
    return false;
}











bool hasIncreasingSubarrays(vector<int> &A, int k)
{
    int n = A.size(), up = 1, pre_max_up = 0, res = 0;
 
    for (int i = 1; i < n; ++i)
    {
        if (A[i] > A[i - 1])
        {
            up++;
        }
 
        else
        {
            pre_max_up = up;
            up = 1;
        }
 
        res = max({res, up / 2, min(pre_max_up, up)});
    }
 
    return res >= k;
}

int maxIncreasingSubarrays(vector<int> &nums)
{
    int st = 1, en = nums.size() / 2;
    int ans = 0;

    while (st <= en)
    {
        int mid = st + (en - st) / 2;

        if (hasIncreasingSubarrays(nums, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    return ans;
}