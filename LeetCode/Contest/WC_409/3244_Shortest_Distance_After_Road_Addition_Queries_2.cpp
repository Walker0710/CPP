#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(set<int> &s, int l, int r)
{
    auto it_start = s.lower_bound(l);
    auto it_end = s.upper_bound(r);

    s.erase(it_start, it_end);
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &Q)
{
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(i);
    }

    vector<int> ans;

    for (auto &i : Q)
    {
        int x = i[0];
        int y = i[1];

        solve(s, x + 1, y - 1);

        ans.push_back(s.size() - 1);
    }

    return ans;
}