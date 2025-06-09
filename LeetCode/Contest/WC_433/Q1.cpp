#include <bits/stdc++.h>

using namespace std;

// << ,

int subarraySum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pre(n, 0);
    pre[0] = nums[0];

    for(int i = 1; i<n; i++) {
        pre[i] = pre[i-1] + nums[i];
    }

    int ans = 0;

    for(int i = 0; i<n; i++) {
        if(max(0, i-nums[i]) == 0)
        ans = ans + pre[i];

        else {
            ans = ans + pre[i] - pre[i - nums[i] - 1];
        }
    }

    return ans;
}
