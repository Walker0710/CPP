#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumLevels(vector<int> &possible)
{
    int n = possible.size();
    vector<int> pref(n + 1, 0);

    if (possible[0] == 0)
        pref[0] = -1;

    else
        pref[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (possible[i] == 0)
            pref[i] = pref[i - 1] - 1;

        else
            pref[i] = pref[i - 1] + 1;
    }

    int maxii = 0;

    for (int i = 0; i < n; i++)
    {
        int aliceScore = pref[i];
        int bobScore = pref[n - 1] - pref[i];

        if (i != n - 1 && aliceScore > bobScore)
            return i + 1;
    }

    return -1;
}