#include <bits/stdc++.h>

using namespace std;

// << ,

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();

    int maxi = *max_element(nums1.begin(), nums1.end());

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        nums2[i] *= k;
    }

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {

        int limit = maxi / nums2[i] + 1;

        for (int j = 0; j < limit; j++)
        {
            if (mp.find(nums2[i] * j) != mp.end())
            {
                ans = ans + mp[nums2[i] * j];
            }
        }
    }

    return ans;
}

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    unordered_map<int, int> count;
    long long result = 0;

    for (int y : nums2)
    {
        count[y * k]++;
    }

    for (int x : nums1)
    {
        for (int d = 1; 1LL * d * d <= x; ++d)
        {
            if (x % d == 0)
            {
                if (count.count(d))
                {
                    result += count[d];
                }

                int other = x / d;

                if (other != d && count.count(other))
                {
                    result += count[other];
                }
            }
        }
    }
    return result;
}