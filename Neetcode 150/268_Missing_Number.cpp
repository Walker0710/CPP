#include <bits/stdc++.h>

using namespace std;

// << ,

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xorr = n;

    for(int i = 0; i<n; i++) {
        xorr = xorr^(i^nums[i]);
    }

    return xorr;
}