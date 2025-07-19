#include <bits/stdc++.h>

using namespace std;

// << ,

void bfs(int node, unordered_map<int, list<int>> &adj, int n, vector<int> &k)
{
    queue<pair<int, int>> q;
    q.push({node, 0});

    vector<int> dist(n + 1, INT_MAX);
    dist[node] = 0;

    while (!q.empty())
    {
        auto [cur, d] = q.front();
        q.pop();

        for (int neigh : adj[cur])
        {
            if (dist[neigh] > d + 1)
            {
                dist[neigh] = d + 1;
                q.push({neigh, dist[neigh]});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == node)
            continue;
        if (dist[i] != INT_MAX)
            k[dist[i] - 1]++;
    }
}

vector<int> countOfPairs(int n, int x, int y)
{
    unordered_map<int, list<int>> adj;
    vector<int> k(n);

    for (int i = 1; i < n; i++)
    {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }

    if (x != y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i, adj, n, k);
    }

    return k;
}