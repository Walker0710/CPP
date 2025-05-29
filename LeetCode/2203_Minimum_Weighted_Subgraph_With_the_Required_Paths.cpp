#include <bits/stdc++.h>

using namespace std;

// << ,

vector<long long> dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int vertices, int source)
{
    vector<long long> dist(vertices, LLONG_MAX);
    set<pair<long long, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        auto [nodeDistance, topNode] = *st.begin();
        st.erase(st.begin());

        for (auto [neighbor, weight] : adj[topNode])
        {
            if (nodeDistance + weight < dist[neighbor])
            {
                auto record = st.find({dist[neighbor], neighbor});
                if (record != st.end())
                    st.erase(record);

                dist[neighbor] = nodeDistance + weight;
                st.insert({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
{
    // Original and reversed adjacency list
    unordered_map<int, list<pair<int, int>>> adj, revAdj;

    for (const auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        adj[u].emplace_back(v, w);
        revAdj[v].emplace_back(u, w); // Reverse edge
    }

    vector<long long> src1Dist = dijkstra(adj, n, src1);
    vector<long long> src2Dist = dijkstra(adj, n, src2);
    vector<long long> destDist = dijkstra(revAdj, n, dest); // From dest in reversed graph

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if (src1Dist[i] == LLONG_MAX || src2Dist[i] == LLONG_MAX || destDist[i] == LLONG_MAX)
            continue;

        ans = min(ans, src1Dist[i] + src2Dist[i] + destDist[i]);
    }

    return ans == LLONG_MAX ? -1 : ans;
}
