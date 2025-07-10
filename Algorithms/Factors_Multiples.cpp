#include <bits/stdc++.h>

using namespace std;

// << ,

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