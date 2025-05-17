#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(int index, int target, vector<int> &nums, vector<int> &toPush, vector<vector<int>> &ans) {
    if(target == 0) {
        ans.push_back(toPush);
        return;
    }

    if (index >= nums.size() || target < 0) 
    return;

    // exc 
    solve(index + 1, target, nums, toPush, ans);

    //inc
    toPush.push_back(nums[index]);
    solve(index, target - nums[index], nums, toPush, ans);
    toPush.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> toPush;
    solve(0, target, candidates, toPush, ans);
    return ans;       
}