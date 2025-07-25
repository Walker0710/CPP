#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }

        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

string longestPrefix(string s)
{
    int n = s.size();
    vector<int> z = z_function(s);
    int maxLength = 0;

    for (int i = 1; i < n; i++)
    {
        if (i + z[i] == n)
        {
            maxLength = max(maxLength, z[i]);
        }
    }

    return s.substr(0, maxLength);
}