#include <bits/stdc++.h>

using namespace std;

// << ,

void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &dist)
{
    for (auto i : adj[node])
    {
        if (i == parent)
        continue;

        dist[i] = dist[node] + 1;

        DFS(i, node, adj, dist);
    }
}

int maximum_distance(vector<int> &dist, int n)
{
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        if (dist[i] > dist[mx])
        {
            mx = i;
        }
    }

    return mx;
}

vector<int> Diameter_distance(vector<vector<int>> &adj)
{
    int n = adj.size() + 1;
    vector<vector<int>> graph(n + 1);

    for (auto i : adj)
    {
        int x = i[0];
        int y = i[1];

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> distX(n + 1, 0);
    DFS(0, -1, graph, distX);

    int y = maximum_distance(distX, n);
    vector<int> distY(n + 1, 0);
    DFS(y, -1, graph, distY);

    int z = maximum_distance(distY, n);
    vector<int> distZ(n + 1, 0);
    DFS(z, -1, graph, distZ);

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(max(distY[i], distZ[i]));
    }

    return ans;
}

int minimumDiameterAfterMerge(vector<vector<int>> &arr, vector<vector<int>> &brr)
{
    if (arr.size() == 0 and brr.size() == 0)
        return 1;

    vector<int> distA = Diameter_distance(arr);
    vector<int> distB = Diameter_distance(brr);

    int ax = *max_element(distA.begin(), distA.end());
    int bx = *max_element(distB.begin(), distB.end());
    int am = *min_element(distA.begin(), distA.end());
    int bm = *min_element(distB.begin(), distB.end());

    int mx = max(ax, bm + 1 + am);
    mx = max(bx, mx);

    return mx;
}