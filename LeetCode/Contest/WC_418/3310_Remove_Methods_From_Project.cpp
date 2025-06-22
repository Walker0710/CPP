#include <bits/stdc++.h>

using namespace std;

// << ,

void dfs(int node, vector<int> adj[], vector<int> &visited)
{
    visited[node] = 1;
    for (auto &it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited);
        }
    }
}

vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
{
    vector<int> adj[n];
    for (auto it : invocations)
    {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> visited(n, 0);

    dfs(k, adj, visited);

    bool suspicious = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            for (auto it : adj[i])
            {
                if (visited[it])
                    suspicious = false;
            }
        }
    }

    vector<int> ans;

    if (suspicious)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                ans.push_back(i);
        }
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            ans.push_back(i);
        }
    }
    return ans;
}