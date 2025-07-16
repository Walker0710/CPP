#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> Z_func(string s)
{
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);

    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
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

int minimumTimeToInitialState(string s, int k)
{
    vector<int> z = Z_func(s);

    int cnt = 0;

    for (int i = k; i < z.size(); i += k)
    {
        cnt++;

        if (z[i] == s.size() - i)
        {
            return cnt;
        }
    }

    return cnt + 1;
}