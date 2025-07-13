#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for(auto edg : edges) {
        int u = edg[0];
        int v = edg[1];
        int w = edg[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto top = pq.top();

        int node = top.second;
        int dis = top.first;

        pq.pop();

        if(dist[node] != dis)
        continue;

        for(auto neigh : adj[node]) {
            int neightNode = neigh.first;
            int len = neigh.second;

            if(len + dis < dist[neightNode]) {
                if(len + dis < disappear[neightNode]) {
                    dist[neightNode] = len + dis;

                    pq.push({dist[neightNode], neightNode});
                }
            }
        }
    }

    for(int i = 0; i<n; i++) {
        if(dist[i] == INT_MAX)
        dist[i] = -1;
    }

    return dist;   
}