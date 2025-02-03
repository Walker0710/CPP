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

//Kmp algorithm
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