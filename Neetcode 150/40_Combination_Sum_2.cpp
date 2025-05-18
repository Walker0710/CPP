#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(int index, int target, vector<int> &nums, vector<int> &toPush, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(toPush);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {

        if (i > index && nums[i] == nums[i - 1])
            continue;

        if (nums[i] > target)
            break;

        toPush.push_back(nums[i]);
        solve(i + 1, target - nums[i], nums, toPush, ans);
        toPush.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> toPush;
    sort(candidates.begin(), candidates.end());
    solve(0, target, candidates, toPush, ans);
    return ans;
}


//2nd approch 

void dfs(vector<int> &candidates, int target, int i, vector<int> &cur, vector<vector<int>> &res, int total)
{
    if (total == target)
    {
        res.push_back(cur);
        return;
    }

    if (total > target || i == candidates.size())
    {
        return;
    }

    cur.push_back(candidates[i]);
    dfs(candidates, target, i + 1, cur, res, total + candidates[i]);
    cur.pop_back();

    while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
    {
        i++;
    }
    dfs(candidates, target, i + 1, cur, res, total);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    dfs(candidates, target, 0, cur, res, 0);
    return res;
}