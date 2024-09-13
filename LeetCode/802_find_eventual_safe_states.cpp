#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

//kahn's algo
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<int> adj[n];
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[graph[i][j]].push_back(i);
            indegree[i]++;
        }
    }

    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neigh : adj[front])
        {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

//dfs
bool dfs(int src, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &safe)
{
    vis[src] = 1;
    pathVis[src] = 1;

    for (auto child : graph[src])
    {
        if (!vis[child])
        {
            if (!dfs(child, graph, vis, pathVis, safe))
            {
                return false;
            }
        }
        else if (pathVis[child])
        {
            return false;
        }
    }

    pathVis[src] = 0;
    safe[src] = 1;
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> safe(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, graph, vis, pathVis, safe);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (safe[i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}