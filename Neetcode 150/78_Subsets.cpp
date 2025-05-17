#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(int index, vector<int> &nums, vector<int> &toPush, vector<vector<int>> &ans) {
    if(index >= nums.size()) {
        ans.push_back(toPush);
        return ;
    }

    // exc
    solve(index + 1, nums, toPush, ans);

    //inc
    toPush.push_back(nums[index]);
    solve(index + 1, nums, toPush, ans);
    toPush.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> toPush;
    solve(0, nums, toPush, ans);
    return ans;
}