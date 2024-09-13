#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

using namespace std;

int solve(vector<int> &nums, int index, unordered_map<int, bool> &yo) {

    if(index >= nums.size())
    return 0;

    int ans = 0;
    int inc = 0;

    //deleting it
    if(yo[index] == false) {

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == nums[index] + 1 || nums[i] == nums[index] - 1)
            yo[index] = true;
        }

        inc = nums[index] + solve(nums, index+1, yo);
    }

    //not deleting
    int exc = solve(nums, index+1, yo);

    ans = max(inc, exc);
    return ans;
}

int deleteAndEarn(vector<int>& nums) {
    unordered_map<int, bool> yo;

    for(int i = 0; i<nums.size(); i++) 
    yo[i] = false;

    return solve(nums, 0, yo);
}
        
