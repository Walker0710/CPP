#include <bits/stdc++.h>

using namespace std;

// << ,

// 1st approch n^2 logn
int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            adj[i].push_back({j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            adj[j].push_back({i, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
        }
    }

    vector<int> key(n);
    vector<int> mst(n);
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 0; v < n; v++)
        {

            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min wli node ko true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adj[u])
        {

            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (key[i] != INT_MAX)
            ans = ans + key[i];
    }
    return ans;
}



// 2nd apprch n^2
int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size(), node = 0;
    vector<int> dist(n, 100000000);
    vector<bool> visit(n, false);
    int edges = 0, res = 0;

    while (edges < n - 1)
    {
        visit[node] = true;
        int nextNode = -1;
        
        for (int i = 0; i < n; i++)
        {
            if (visit[i])
            continue;
            
            int curDist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
            
            dist[i] = min(dist[i], curDist);
            
            if (nextNode == -1 || dist[i] < dist[nextNode])
            {
                nextNode = i;
            }
        }
        
        res += dist[nextNode];
        node = nextNode;
        edges++;
    }
    return res;
}