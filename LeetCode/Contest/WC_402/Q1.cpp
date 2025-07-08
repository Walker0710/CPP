#include <bits/stdc++.h>

using namespace std;

// << ,

int countCompleteDayPairs(vector<int> &hours)
{
    int n = hours.size();

    for (int i = 0; i < n; i++)
    {
        hours[i] = hours[i] % 24;
    }

    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int yoo = (24 - hours[i]) % 24;

        if (mp.find(yoo) != mp.end())
        {
            ans = ans + mp[yoo];
        }

        mp[hours[i]]++;
    }

    return ans;
}