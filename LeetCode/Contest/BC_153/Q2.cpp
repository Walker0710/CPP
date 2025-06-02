#include <bits/stdc++.h>

using namespace std;

// << ,

int maxActiveSectionsAfterTrade(string s)
{
    int def = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            def++;
    }

    int st = 0;
    int ans = INT_MAX;
    int i = 0;

    while (i < s.length())
    {
        int cnt = 0;

        if (s[i] == '0' && s[i + 1] == '1')
        {
            int rec = i;
            i++;

            while (s[i] == '1')
            {
                cnt++;
                i++;
            }

            if (s[i] == '0' && cnt < ans)
            {
                ans = cnt;
                st = rec + 1;
            }
        }
    }

    if (st == 0)
        return def;

    int st = 0;
    int ans = INT_MAX;
    int i = 0;

    while (i < s.length())
    {
        int cnt = 0;

        if (s[i] == '0' && s[i + 1] == '1')
        {
            int rec = i;
            i++;

            while (s[i] == '1')
            {
                cnt++;
                i++;
            }

            if (s[i] == '0' && cnt < ans)
            {
                ans = cnt;
                st = rec + 1;
            }
        }
    }
}