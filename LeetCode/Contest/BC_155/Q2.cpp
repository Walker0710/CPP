#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> baseUnitConversions(vector<vector<int>> &conversions)
{
    unordered_map<long long, list<pair<long long, long long>>> adj;

    for (long long i = 0; i < conversions.size(); i++)
    {
        adj[conversions[i][0]].push_back({conversions[i][1], conversions[i][2]});
    }

    const long long MOD = 1000000007;

    queue<pair<long long, long long>> q;
    q.push({0, 1});
    vector<int> ans(conversions.size() + 1);
    vector<bool> visi(conversions.size() + 1);
    visi[0] = true;
    ans[0] = 1;

    while (!q.empty())
    {
        auto topp = q.front();
        q.pop();

        for (auto &neigh : adj[topp.first])
        {
            if (!visi[neigh.first])
            {
                long long prod = (neigh.second % MOD) * (topp.second % MOD) % MOD;

                q.push({neigh.first, prod});
                ans[neigh.first] = prod;
                visi[neigh.first] = true;
            }
        }
    }

    return ans;
}