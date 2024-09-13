#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

void topo(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<pair<int, int>>> &adj)
{
    visited[node] = true;

    for (auto neigh : adj[node])
    {
        if (!visited[neigh.first])
        {
            topo(neigh.first, visited, s, adj);
        }
    }
    s.push(node);
}

void getShortestPath(int src, vector<int> &dist, stack<int> &s, unordered_map<int, list<pair<int, int>>> &adj)
{
    dist[src] = 0;

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (dist[top] == INT32_MAX)
            continue;

        for (auto i : adj[top])
        {
            if (dist[top] + i.second < dist[i.first])
            {
                dist[i.first] = dist[top] + i.second;
            }
        }
    }
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < times.size(); i++)
    {

        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 1; i < n + 1; i++)
    {

        if (!visited[i])
        {

            topo(i, visited, s, adj);
        }
    }

    vector<int> dist(n, INT32_MAX);
    getShortestPath(k, dist, s, adj);

    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans;
}

// 2nd approch
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int, int>> adj[n + 1];

    for (auto vec : times)
    {
        adj[vec[0]].push_back({vec[1], vec[2]});
    }

    vector<int> time(n + 1, INT_MAX);
    time[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (!pq.empty())
    {
        int currTime = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currTime > time[node])
            continue;

        for (auto it : adj[node])
        {
            int next = it.first;
            int timetaken = it.second;
            
            if (currTime + timetaken < time[next])
            {
                pq.push({currTime + timetaken, next});
                time[next] = currTime + timetaken;
            }
        }
    }

    int answer = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        answer = max(answer, time[i]);
    }

    return (answer != INT_MAX) ? answer : -1;
}
