#include <bits/stdc++.h>

using namespace std;

// << ,

int countCoveredBuildings(int n, vector<vector<int>> &buildings)
{
    if (buildings.empty())
        return 0;

    unordered_map<int, vector<int>> mp;
    unordered_map<int, vector<int>> mpp;

    for (const auto &building : buildings)
    {
        int x = building[0];
        int y = building[1];
        mp[x].push_back(y);
        mpp[y].push_back(x);
    }

    for (auto &i : mp)
    {
        sort(i.second.begin(), i.second.end());
    }
    
    for (auto &i : mpp)
    {
        sort(i.second.begin(), i.second.end());
    }

    int cnt = 0;

    for (auto num : buildings)
    {
        int x = num[0];
        int y = num[1];

        vector<int> &row = mp[x];
        bool l = !row.empty() && row.front() < y;

        bool r = !row.empty() && row.back() > y;

        vector<int> &col = mpp[y];
        bool a = !col.empty() && col.front() < x;

        bool b = !col.empty() && col.back() > x;

        if (l && r && a && b)
        {
            cnt++;
        }
    }

    return cnt;
}