#include <bits/stdc++.h>

using namespace std;

// << ,

int jump(vector<int> &nums)
{
    int res = 0, l = 0, r = 0;

    while (r < nums.size() - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        res++;
    }
    return res;
}

int jump(vector<int> &nums)
{
    int ans = 0;
    int i = 0;

    if (nums.size() == 1)
        return 0;

    int currentEnd = 0, farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        farthest = max(farthest, i + nums[i]);

        if (i == currentEnd)
        {
            ans++;
            currentEnd = farthest;
        }
    }

    return ans;
}
