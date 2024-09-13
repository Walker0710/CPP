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

vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int source)
{ // time complexity = O(Elog(V))

    // adj list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = 1;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {

        dist[i] = INT32_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        for (auto neigh : adj[topNode])
        {

            if (nodeDistance + neigh.second < dist[neigh.first])
            {

                auto record = st.find(make_pair(dist[neigh.first], neigh.first));

                // if record found then erase it
                if (record != st.end())
                {

                    st.erase(record);
                }

                // distance update
                dist[neigh.first] = nodeDistance + neigh.second;

                // record push in set
                st.insert(make_pair(dist[neigh.first], neigh.first));
            }
        }
    }
    return dist;
}

int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
{
    int n = patience.size();
    vector<int> dist = dijkstra(edges, n, 0);

    for (int i = 0; i < n; i++)
        dist[i] = dist[i] * 2;

    int minTime = 0;

    for (int i = 1; i < n; i++)
    {
        if (dist[i] > patience[i])
        {
            int ahead = (dist[i] - 1) % patience[i] + 1;
            minTime = max(minTime, 2 * dist[i] - ahead);
        }

        else
            minTime = max(minTime, dist[i]);
    }

    return minTime + 1;
}

// leetcode
int res = 0;
int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &p)
{
    int n = p.size();
    vector<vector<int>> adj(n);
    for (const vector<int> &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    queue<int> q;
    vector<bool> visited(n, false);
    visited[0] = true;
    for (int next : adj[0])
    {
        q.push(next);
        visited[next] = true;
    }
    int dist = 1;
    while (!q.empty())
    {
        int m = q.size();
        for (int i = 0; i < m; i++)
        {
            int curr = q.front();
            q.pop();
            res = max(res, dist * 2 + (dist * 2 - 1) / p[curr] * p[curr]);
            for (int next : adj[curr])
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        dist++;
    }
    return res + 1;
}