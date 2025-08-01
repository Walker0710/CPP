#include <bits/stdc++.h>

using namespace std;

// << ,

#define ll long long
ll minOperations(vector<vector<int>> &queries)
{
    ll ans = 0;
    for (int i = 0; i < queries.size(); i++)
    {
        ll start = queries[i][0], end = queries[i][1];
        ll ops = 0;

        for (ll d = 1, prev = 1; d < 17; d++)
        {
            ll cur = prev * 4LL;
            // find intersection of interval given in queries with [prev, cur - 1]
            ll l = max(start, prev), r = min(end, cur - 1);

            if (r >= l)
                ops += (r - l + 1) * d; // intersection occurs
            prev = cur;
        }
        ans += (ops + 1) / 2; // since everytime we can choose 2 numbers we need atmost ceil(ops / 2) operations
    }
    return ans;
}