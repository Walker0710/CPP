#include <bits/stdc++.h>

using namespace std;

// << ,

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    // Step 1: Find the first pair (nums[i], nums[i+1]) such that nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }

    // Step 2: If there is no such pair, reverse the entire array
    if (i == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the smallest element in the subarray nums[i+1, n-1] that is greater than nums[i]
    int j = n - 1;
    while (j > i && nums[j] <= nums[i])
    {
        j--;
    }

    // Step 4: Swap nums[i] and the found element
    swap(nums[i], nums[j]);

    // Step 5: Reverse the subarray nums[i+1, n-1]
    reverse(nums.begin() + i + 1, nums.end());
}