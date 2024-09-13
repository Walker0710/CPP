#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <set>
#include <numeric>

using namespace std;

int solve(int node, int maxMove, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &visi)
{
    int ans = 0;
    visi[node] = true;

    for (auto neigh : adj[node])
    {
        if (maxMove - neigh.second - 1 < 0)
        {
            ans = ans + maxMove;
        }

        else if (maxMove - neigh.second - 1 == 0 && !visi[neigh.second])
        {
            ans = ans + maxMove;
            visi[neigh.second] = true;
        }

        else if (!visi[node])
            ans = ans + solve(neigh.first, maxMove - neigh.second - 1, adj, visi);
    }

    return ans;
}

int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<bool> visi(n);

    return solve(0, maxMoves, adj, visi) + 1;
}

// 2nd approch
int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
{
    if(edges.size() == 0) 
    return 1;
    
    vector<pair<int, int>> adj[n];
    int cnt = 0;
    
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> v(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    q.push({0, 0});
    v[0] = 0;
    
    while (!q.empty())
    {
        int pos = q.top().second, wt = q.top().first;
        q.pop();
        for (auto it : adj[pos])
        {
            if (v[it.first] > wt + it.second + 1)
            {
                v[it.first] = it.second + wt + 1;
                q.push({v[it.first], it.first});
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (maxMoves >= v[i])
        {
            cnt++;
        }
    }
    
    for (auto it : edges)
    {
        int l1 = max(0, maxMoves - v[it[0]]), l2 = max(0, maxMoves - v[it[1]]);
        cnt += min(it[2], l1 + l2);
    }
    return cnt;
}