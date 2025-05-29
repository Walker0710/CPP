#include <bits/stdc++.h>

using namespace std;

// << ,

int dfs(unordered_map<int, list<pair<int, int>>> &adj, int node, int k, int t, unordered_map<string, int> &dp)
{
    if (k == 0 && t > 0)
    return 0;
    
    if (t <= 0 || k < 0)
    return INT_MIN;

    string key = to_string(node) + "-" + to_string(k) + "-" + to_string(t);

    if (dp.count(key))
    return dp[key];

    int ans = INT_MIN;

    for (auto &neigh : adj[node])
    {
        int score = neigh.second;
        int nextNode = neigh.first;
        int val = dfs(adj, nextNode, k - 1, t - score, dp);

        if (val != INT_MIN)
        {
            ans = max(ans, score + val);
        }
    }

    return dp[key] = ans;
}

int maxWeight(int n, vector<vector<int>> &edges, int k, int t)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto &edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int ans = INT_MIN;
    unordered_map<string, int> dp;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dfs(adj, i, k, t, dp));
    }

    return ans == INT_MIN ? -1 : ans;
}