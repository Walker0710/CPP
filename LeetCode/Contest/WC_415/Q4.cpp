#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> zFunction(string_view s)
{
    int n = size(s);
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
        if (i + z[i] - 1 > r)
        {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int jump(vector<int> &nums)
{
    int ans = 0;
    for (int l = 0, r = 0, n = size(nums); r < n; ++ans)
    {
        int farthest = r;
        for (int i = l; i <= r; ++i)
        {
            farthest = max(farthest, nums[i] + i);
        }
        if (farthest == r)
        {
            return -1;
        }
        l = r;
        r = farthest;
    }
    return ans;
}

int minValidStrings(vector<string> &words, string t)
{
    const int n = size(t);
    vector<int> prefixes(n);

    for (const auto &w : words)
    {
        const auto z = zFunction(w + '#' + t);
        for (int i = size(w) + 1; i < size(z); ++i)
        {
            prefixes[i - size(w) - 1] = max(prefixes[i - size(w) - 1], z[i]);
        }
    }
    return jump(prefixes);
}