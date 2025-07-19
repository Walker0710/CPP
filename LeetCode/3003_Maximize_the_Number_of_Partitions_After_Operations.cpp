#include <bits/stdc++.h>

using namespace std;

// << ,

unordered_map<long long, int> mp;

int solve(int ind, int mask, bool flag, string &s, int k)
{

    long long key = (1LL * ind << 27) | (1LL * mask << 1) | flag;

    if (mp.count(key))
    {
        return mp[key];
    }

    if (ind == s.size())
    {
        return 0;
    }

    int charIndex = s[ind] - 'a';
    int newMask = mask | (1 << charIndex);

    int uniqueCount = __builtin_popcount(newMask);

    int res;

    if (uniqueCount > k)
    {
        res = 1 + solve(ind + 1, 1 << charIndex, flag, s, k);
    }

    else
    {
        res = solve(ind + 1, newMask, flag, s, k);
    }

    if (flag)
    {

        for (int ch = 0; ch < 26; ++ch)
        {

            if (ch == charIndex)
                continue;

            int changedMask = mask | (1 << ch);
            int changedCount = __builtin_popcount(changedMask);

            if (changedCount > k)
            {
                res = max(res, 1 + solve(ind + 1, 1 << ch, false, s, k));
            }

            else
            {
                res = max(res, solve(ind + 1, changedMask, false, s, k));
            }
        }
    }

    return mp[key] = res;
}

int maxPartitionsAfterOperations(string s, int k)
{
    return solve(0, 0, true, s, k) + 1;
}