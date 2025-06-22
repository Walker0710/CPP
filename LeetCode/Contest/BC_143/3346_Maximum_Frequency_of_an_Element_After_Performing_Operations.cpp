#include <bits/stdc++.h>

using namespace std;

// << ,

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    unordered_map<int, int> freq;

    for(auto &a : nums) {
        freq[a]++;
    }

    sort(nums.begin(), nums.end());
    int ans = 0;

    for(auto &[ele, fre] : freq) {

        // case 1
        auto it1 = lower_bound(nums.begin(), nums.end(), ele - k) - nums.begin();
        auto it2 = upper_bound(nums.begin(), nums.end(), ele + k) - nums.begin();
        
        int cnt = min(numOperations, static_cast<int>(it2 - it1 - fre));

        ans = max(ans, fre + cnt);

        // case 2
        auto it3 = lower_bound(nums.begin(), nums.end(), ele) - nums.begin();
        auto it4 = upper_bound(nums.begin(), nums.end(), ele + 2*k) - nums.begin();

        ans = max(ans, min(static_cast<int>(it4 - it3), numOperations));

    }

    return ans;
}