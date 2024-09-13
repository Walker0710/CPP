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

void solve(int node, int distance, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &visi, vector<int> &yoo, int &mini) 
{

    if (distance < 0) {
        if(yoo.size() < mini) 
        mini = yoo.size();
        return;
    }

    visi[node] = true;

    for (auto i : adj[node])
    {
        if (!visi[i.first])
        {
            yoo.push_back(i.first);
            solve(i.first, distance - i.second, adj, visi, yoo, mini);
            yoo.pop_back();
        }
    }
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    int ans = 0;
    int miniMini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        vector<int> yoo;
        vector<bool> visi(n);
        int mini = INT_MAX;

        solve(i, distanceThreshold, adj, visi, yoo, mini);

        if (miniMini >= mini) {
            ans = i;
            miniMini = mini;
        }
    }
    return ans;
}