#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

// rec only
vector<int> dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int vertices, int source)
{
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {

        dist[i] = INT32_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {

        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        for (auto neigh : adj[topNode])
        {

            if (nodeDistance + neigh.second < dist[neigh.first])
            {

                auto record = st.find(make_pair(dist[neigh.first], neigh.first));

                // if record found then erase it
                if (record != st.end())
                {

                    st.erase(record);
                }

                // distance update
                dist[neigh.first] = nodeDistance + neigh.second;

                // record push in set
                st.insert(make_pair(dist[neigh.first], neigh.first));
            }
        }
    }

    return dist;
}

void dfs(int source, int target, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &visi, vector<int> &dijk, int &ans)
{

    if (source == target)
    {
        ans++;
        return;
    }

    visi[source] = true;

    for (auto neigh : adj[source])
    {
        if (!visi[neigh.first] && (dijk[source] > dijk[neigh.first]))
        {
            dfs(neigh.first, target, adj, visi, dijk, ans);
        }
    }

    visi[source] = false;
}

int countRestrictedPaths(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dijk = dijkstra(adj, n, n - 1);
    vector<bool> visi(n);

    int ans = 0;
    dfs(0, n - 1, adj, visi, dijk, ans);

    return ans;
}

//rec + memo
vector<int> dist;
int node;
int MOD = 1e9 + 7;
vector<int> dp;
int dfs(int i, vector<pair<int, int>> adj[])
{
    if (i == node)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int ans = 0;
    for (const auto &[a, b] : adj[i])
        if (dist[i] > dist[a])
        {
            ans += dfs(a, adj);
            ans %= MOD;
        }

    return dp[i] = ans;
}

int countRestrictedPaths(int n, vector<vector<int>> &edges)
{
    node = n;
    vector<pair<int, int>> adj[n + 1];
    dp.resize(n + 1, -1);
    for (const auto &i : edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    dist.resize(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, n});

    while (!q.empty())
    {
        const auto [a, b] = q.top();
        q.pop();
        if (dist[b] != INT_MAX)
            continue;
        dist[b] = a;
        for (const auto &[i, j] : adj[b])
            if (dist[i] == INT_MAX)
                q.push({a + j, i});
    }

    return dfs(1, adj);
}