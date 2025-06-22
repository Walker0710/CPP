#include <bits/stdc++.h>

using namespace std;

// << ,

long long maximizeSumOfWeights(vector<vector<int>> &edges, int k)
{
    int n = 0;
    for (auto &edge : edges)
    {
        n = max(n, max(edge[0], edge[1]) + 1);
    }

    vector<vector<pair<int, int>>> adj(n);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dp0(n, 0), dp1(n, 0);

    // Recursive DFS function
    function<void(int, int)> dfs = [&](int u, int parent)
    {
        dp0[u] = 0;
        dp1[u] = 0;
        vector<long long> gains;

        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first, w = neighbor.second;
            if (v != parent)
            {
                dfs(v, u);
                long long gain = dp1[v] + w - dp0[v];
                gains.push_back(gain);
                dp0[u] += dp0[v];
            }
        }

        sort(gains.rbegin(), gains.rend()); // Sort in descending order
        long long sum_gains = 0;
        int limit = min((int)gains.size(), k);

        for (int i = 0; i < limit; i++)
        {
            if (gains[i] > 0)
            {
                sum_gains += gains[i];
            }
        }
        dp0[u] += sum_gains;

        if (k >= 1)
        {
            long long sum1 = 0;
            int limit1 = min((int)gains.size(), k - 1);

            for (int i = 0; i < limit1; i++)
            {
                if (gains[i] > 0)
                {
                    sum1 += gains[i];
                }
            }

            dp1[u] = dp0[u] - sum_gains + sum1;
        }

        else
        {
            dp1[u] = dp0[u];
        }
    };

    dfs(0, -1);
    return max(dp0[0], dp1[0]);
}