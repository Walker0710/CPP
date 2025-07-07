#include <bits/stdc++.h>

using namespace std;

// << ,

int winningPlayerCount(int n, vector<vector<int>> &pick)
{
    map<pair<int, int>, int> mp;
 
    for (auto i : pick)
    {
        int player = i[0];
        int color = i[1];

        mp[{player, color}]++;
    }

    vector<bool> seen(pick.size(), false);
    int count = 0;
 
    for (auto i : mp)
    {
        if ((i.second > i.first.first) && (seen[i.first.first] != true))
        {
            count++;
            seen[i.first.first] = true;
        }
    }
 
    return count;
}