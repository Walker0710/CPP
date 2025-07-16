#include <bits/stdc++.h>

using namespace std;

// << ,

int minOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    return lower_bound(nums.begin(), nums.end(), k) - nums.begin();
}