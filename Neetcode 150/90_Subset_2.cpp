#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(int index, vector<int> &nums, vector<int> &toPush, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(toPush);
        return;
    }

    toPush.push_back(nums[index]);
    solve(index + 1, nums, toPush, ans);
    toPush.pop_back();

    while (index + 1 < nums.size() && nums[index] == nums[index + 1])
    {
        index++;
    }

    solve(index + 1, nums, toPush, ans);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> toPush;
    sort(nums.begin(), nums.end());

    solve(0, nums, toPush, ans);

    return ans;
}

// 2nd approch

void backtrack(int i, vector<int> &subset, vector<vector<int>> &res, vector<int> &nums)
{
    res.push_back(subset);
    
    for (int j = i; j < nums.size(); j++)
    {
        if (j > i && nums[j] == nums[j - 1])
        {
            continue;
        }
 
        subset.push_back(nums[j]);
        backtrack(j + 1, subset, res, nums);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    backtrack(0, subset, res, nums);
    return res;
}