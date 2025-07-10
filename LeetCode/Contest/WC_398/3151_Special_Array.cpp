#include <bits/stdc++.h>

using namespace std;

// << ,

bool isArraySpecial(vector<int> &nums)
{
    if(nums.size() == 1)
    return true;

    bool ans = true;

    for(int i = 0; i<nums.size() - 1; i++) {
        if(i == 0) {
            if(nums[i]%2 == nums[i+1]%2) {
                ans = false;
                break;
            }
        }

        else {
            if(nums[i-1]%2 == nums[i]%2 || nums[i]%2 == nums[i+1]%2) {
                ans = false;
                break;
            }
        }
    }

    return ans;
}