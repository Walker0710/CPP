#include <bits/stdc++.h>

using namespace std;

// << ,

int maxAdjacentDistance(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2) return 0;

    int maxDistance = 0;
    for (int i = 1; i < n; i++) {
        maxDistance = max(maxDistance, abs(nums[i] - nums[i - 1]));
    }

    maxDistance = max(maxDistance, abs(nums[0] - nums[n - 1])); 

    return maxDistance;
}