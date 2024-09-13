#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;

// failed on test case 54
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < redEdges.size(); i++)
    {
        adj[redEdges[i][0]].push_back({redEdges[i][1], 1});
    }

    for (int i = 0; i < blueEdges.size(); i++)
    {
        adj[blueEdges[i][0]].push_back({blueEdges[i][1], 2});
    }

    queue<tuple<int, int, int>> q;
    vector<int> dist(n, INT_MAX);
    q.push({0, 0, 0});
    dist[0] = 0;

    while (!q.empty())
    {
        auto [node, distance, prevColor] = q.front();
        q.pop();

        for (const auto &[neigh, color] : adj[node])
        {
            if (color != prevColor && dist[neigh] > distance + 1)
            {
                dist[neigh] = distance + 1;
                q.push({neigh, dist[neigh], color});
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }

    return dist;
}

//leetcode
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<int> adjRed[n], adjBlue[n];
    for (auto it : redEdges)
    {
        adjRed[it[0]].push_back(it[1]);
    }
    for (auto it : blueEdges)
    {
        adjBlue[it[0]].push_back(it[1]);
    }

    set<pair<int, int>> vis;
    vis.insert({0, -1});
    vector<int> ans(n, -1);
    queue<pair<int, pair<int, int>>> q; 
    q.push({0, {0, -1}});
    
    while (!q.empty())
    {
        int node = q.front().first;
        int length = q.front().second.first;
        int color = q.front().second.second;
        q.pop();
        if (ans[node] == -1)
        {
            ans[node] = length;
        }

        if (color != 0)
        {
            for (auto it : adjRed[node])
            {
                if (vis.find({it, 0}) == vis.end())
                {
                    vis.insert({it, 0});
                    q.push({it, {length + 1, 0}});
                }
            }
        }

        if (color != 1)
        {
            for (auto it : adjBlue[node])
            {
                if (vis.find({it, 1}) == vis.end())
                {
                    vis.insert({it, 1});
                    q.push({it, {length + 1, 1}});
                }
            }
        }
    }
    return ans;
}
