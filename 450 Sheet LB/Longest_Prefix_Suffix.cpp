#include <bits/stdc++.h>

using namespace std;

// << ,

int longestPrefixSuffix(string &s)
{
    int st = 0;
    int en = 1;
    int n = s.length();

    while (en != n)
    {
        if (s[st] != s[en])
        {
            en++;
            st = 0;
        }

        else
        {
            int prev = en;

            while (en < n && s[st] == s[en])
            {
                st++;
                en++;
            }

            if (en == n)
            {
                return en - prev;
            }
        }
    }

    return 0;
}