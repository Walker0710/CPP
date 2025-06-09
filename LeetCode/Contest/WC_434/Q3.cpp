#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int index, int x, vector<int> &nums, int k, bool canSelect, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return 0;

    if (dp[index][canSelect] != -1)
        return dp[index][canSelect];

    int exc = (nums[index] == k ? 1 : 0) + solve(index + 1, x, nums, k, canSelect, dp);

    int inc = 0;

    if (canSelect)
    {
        int cnt = 0;

        for (int i = index; i < nums.size(); i++)
        {
            if (nums[i] + x == k)
                cnt++;

            inc = max(inc, cnt + solve(i + 1, x, nums, k, 0, dp));
        }
    }

    return dp[index][canSelect] = max(inc, exc);
}

int maxFrequency(vector<int> &nums, int k)
{
    int ans = 0;

    for (int x = -50; x <= 50; x++)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, -1));
        ans = max(ans, solve(0, x, nums, k, 1, dp));
    }

    return ans;
}

int maxFrequency(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = 0;

    for (int x = -50; x <= 50; x++)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = nums;

            for (int j = i; j < n; j++)
            {
                for (int p = i; p <= j; p++)
                {
                    temp[p] += x;
                }

                int cnt = 0;
                for (int val : temp)
                {
                    if (val == k)
                        cnt++;
                }

                ans = max(ans, cnt);

                for (int p = i; p <= j; p++)
                {
                    temp[p] -= x;
                }
            }
        }
    }

    return ans;
}


int maxFrequency(vector<int> &nums, int k)
{
    int orig = count(nums.begin(), nums.end(), k), mx = 0;
    
    for (int m = 1; m <= 50; ++m)
    {
        if (m == k)
        continue;
        
        int cur = 0, mxCur = 0;
        
        for (int n : nums)
        {
            cur += n == m ? 1 : n == k ? -1 : 0;
            cur = max(cur, 0);
            mxCur = max(mxCur, cur);
        }

        mx = max(mx, mxCur);
    }

    return orig + mx;
}