#include <bits/stdc++.h>

using namespace std;

// << ,

long long shiftDistance(string s, string t, vector<int> &nextCost, vector<int> &previousCost)
{
    vector<long long> next(nextCost.begin(), nextCost.end());
    vector<long long> prev(previousCost.begin(), previousCost.end());

    for (int i = 1; i < 26; i++)
    {
        next[i] += next[i - 1];
    }

    for (int i = 24; i >= 0; i--)
    {
        prev[i] += prev[i + 1];
    }

    long long totalCost = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            int start = s[i] - 'a';
            int end = t[i] - 'a';

            if (start < end)
            {
                long long forwardCost = next[end - 1] - (start > 0 ? next[start - 1] : 0);
                long long backwardCost = prev[0] - (start + 1 < 26 ? prev[start + 1] : 0) + (end == 25 ? 0 : prev[end + 1]);
                totalCost += min(forwardCost, backwardCost);
            }
            else
            {
                long long backwardCost = prev[end + 1] - (start < 25 ? prev[start + 1] : 0);
                long long forwardCost = next[25] - (start > 0 ? next[start - 1] : 0) + (end != 0 ? next[end - 1] : 0);
                totalCost += min(forwardCost, backwardCost);
            }
        }
    }

    return totalCost;
}