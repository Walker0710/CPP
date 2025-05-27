#include <bits/stdc++.h>

using namespace std;

// << ,

int maxSubArray(vector<int> &nums)
{
    int ans = nums[0];
    int sum = 0;

    for(int i = 0; i<nums.size(); i++) {
        sum = sum + nums[i];
        ans = max(sum, ans);

        if(sum < 0)
        sum = 0;
    }

    return ans;
}