#include <bits/stdc++.h>

using namespace std;

// << ,

int dfs(int u, int parent, vector<pair<int, int>> graph[], int sum, int signalSpeed)
{

    int c = 0;

    for (pair<int, int> child : graph[u])
    {

        int v = child.first, w = child.second;
        if (v == parent)
            continue;

        sum += w;

        c += (sum % signalSpeed == 0) + dfs(v, u, graph, sum, signalSpeed);

        sum -= w;
    }

    return c;
}

vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
{
    int n = edges.size();

    vector<pair<int, int>> graph[n + 1];

    for (vector<int> edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> ans(n + 1, 0);

    for (int i = 0; i < n + 1; i++)
    {
        int total_cnt = 0;
        int pairs = 0;

        for (pair<int, int> child : graph[i])
        {
            int c = (child.second % signalSpeed == 0) + dfs(child.first, i, graph, child.second, signalSpeed);

            pairs += total_cnt * c;
            total_cnt += c;
        }

        ans[i] = pairs;
    }

    return ans;
}