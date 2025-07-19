#include <bits/stdc++.h>

using namespace std;

// << ,

int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    int maxi = 0;

    for (auto [n, f] : mp)
    {
        if (f > maxi)
        {
            maxi = f;
        }
    }

    int sum = 0;

    for (auto [n, f] : mp)
    {
        if (maxi == f)
        {
            sum = sum + maxi;
        }
    }

    return sum;
}