#include <bits/stdc++.h>

using namespace std;

// << ,

int minAnagramLength(string s)
{
    int n = s.length();

    for (int len = 1; len <= n; ++len)
    {
        if (n % len != 0)
            continue;

        unordered_map<char, int> base_freq;
        for (int i = 0; i < len; i++)
        {
            base_freq[s[i]]++;
        }

        bool allMatch = true;
        for (int i = 0; i < n; i += len)
        {
            unordered_map<char, int> curr;
            for (int j = 0; j < len; j++)
            {
                curr[s[i + j]]++;
            }

            if (curr != base_freq)
            {
                allMatch = false;
                break;
            }
        }

        if (allMatch)
            return len;
    }

    return n;
}
