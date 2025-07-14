#include <bits/stdc++.h>

using namespace std;

// << ,

int maximumLengthSubstring(string s)
{
    int n = s.length();
    int l = 0;
    unordered_map<char, int> freq;
    int ans = 0;

    for (int r = 0; r < n; ++r)
    {
        freq[s[r]]++;

        while (freq[s[r]] > 2)
        {
            freq[s[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}