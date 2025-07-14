#include <bits/stdc++.h>

using namespace std;

// << ,

#define ll long long 

long long minOperationsToMakeMedianK(vector<int> &nums, int k)
{
    ll ans = 0;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    if(nums[n/2] == k) {
        return 0;
    }

    if(nums[n/2] < k) {
        for(int i = n/2; i<n && nums[i] < k; i++) {
            ans = ans + (k - nums[i]);
        }

        return ans;
    }

    if(nums[n/2] > k) {
        for(int i = n/2; i>=0 && nums[i] > k; i--) {
            ans = ans + (nums[i] - k);
        }

        return ans;
    }

    return 0;
}