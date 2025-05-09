#include <bits/stdc++.h>

using namespace std;

// << ,

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> yoo;

    for(int i = 0; i<n; i++) {
        yoo[nums[i]]++;
    }

    for(auto pair : yoo) {
        if(pair.second > 1) {
            return true;
        }
    }

    return false;
}