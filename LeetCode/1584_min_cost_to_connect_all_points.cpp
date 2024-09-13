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

int minCostConnectPoints(vector<vector<int>> &points)
{   
    int n = points.size();
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        key[i] = INT32_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT32_MAX;
        int u;

        for (int v = 0; v < n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

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
    for(int i = 0; i<n; i++) {
        if(key[i] != INT32_MAX)
        ans = ans + key[i]; 
    }
    return ans;
}