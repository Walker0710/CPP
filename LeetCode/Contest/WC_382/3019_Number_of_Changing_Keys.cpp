#include <bits/stdc++.h>

using namespace std;

// << ,

int countKeyChanges(string s)
{
    int ans = 0;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (tolower(s[i]) != tolower(s[i + 1]))
        {
            ans++;
        }
    }

    return ans;
}