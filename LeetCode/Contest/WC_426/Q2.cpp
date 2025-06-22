#include <bits/stdc++.h>

using namespace std;

// << ,

int getLargestOutlier(vector<int> &nums)
{
    int total = 0;
    int n = nums.size();
    unordered_map<int, int> yoo;

    for (int i = 0; i < n; i++)
    {
        total += nums[i];
        yoo[nums[i]]++;
    }

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (yoo[(total - nums[i]) / 2] != 0)
        {
            ans = max(ans, nums[i]);
        }
    }

    return ans;
}

int getLargestOutlier(vector<int> &nums)
{
    int ans = INT_MIN, sum = 0;
    unordered_map<int, int> freq;
 
    for (auto n : nums)
    {
        sum += n;
        freq[n * 2]++;
    }
 
    for (auto n : nums)
    {
        int t = sum - n;
 
        if (freq[t] >= 2 || (freq[t] == 1) && (t != n * 2))
            ans = max(ans, n);
    }
 
    return ans;
}