#include <bits/stdc++.h>

using namespace std;

// << ,

#define ll long long

long long countAlternatingSubarrays(vector<int> &nums)
{
    int n = nums.size();
    ll ans = 1;
    int len = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            len++;
        }
        else
        {
            len = 1;
        }
        ans += len;
    }

    return ans;
}