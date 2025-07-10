#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumChairs(string s)
{
    int maxii = 0;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'E')
        {
            cnt++;
        }

        else
        {
            maxii = max(maxii, cnt);
            cnt--;
        }
    }

    return max(maxii, cnt);
}