#include <bits/stdc++.h>

using namespace std;

// << ,

int longestPrefixSuffix(string &s)
{
    int i = 1;
    int j = 0;
    int n = s.length();

    vector<int> lps(n, 0);

    while (i < n)
    {
        if (s[i] == s[j])
        {
            j++;
            lps[i] = j;
            i++;
        }

        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }

            else
            {
                i++;
            }
        }
    }

    return lps[n - 1];
}