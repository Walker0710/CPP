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

// rec only
int dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int vertices, int source)
{
    vector<int> dist(vertices, INT32_MAX);

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neigh : adj[topNode])
        {
            if (nodeDistance + neigh.second < dist[neigh.first])
            {
                auto record = st.find({dist[neigh.first], neigh.first});

                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[neigh.first] = nodeDistance + neigh.second;

                st.insert({dist[neigh.first], neigh.first});
            }
        }
    }

    return dist[vertices - 1];
}

int solve(int node, int target, unordered_map<int, list<pair<int, int>>> &adj, vector<int> &visi, int distance, int &shortestPath)
{
    if (node == target)
    {
        return distance == 0 ? 1 : 0;
    }

    visi[node] = true;
    int ans = 0;

    for (auto neigh : adj[node])
    {
        if (!visi[neigh.first] && distance >= neigh.second)
        {
            ans = (ans + solve(neigh.first, target, adj, visi, distance - neigh.second, shortestPath)) % 1000000007;
        }
    }

    visi[node] = false;
    return ans;
}

int countPaths(int n, vector<vector<int>> &roads)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto i : roads)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    vector<int> visi(n, false);

    int shortestPath = dijkstra(adj, n, 0);

    return solve(0, n - 1, adj, visi, shortestPath, shortestPath);
}

// rec + memo
int solveMem(int node, int target, unordered_map<int, list<pair<int, int>>> &adj, vector<int> &visi, int distance, int &shortestPath, vector<vector<int>> &dp)
{
    if (node == target)
    {
        return distance == 0 ? 1 : 0;
    }

    if(distance < 0)
    return 0;

    if (dp[node][distance] != -1)
        return dp[node][distance];

    visi[node] = true;
    int ans = 0;

    for (auto neigh : adj[node])
    {
        if (!visi[neigh.first] && distance >= neigh.second)
        {
            ans = (ans + solveMem(neigh.first, target, adj, visi, distance - neigh.second, shortestPath, dp)) % 1000000007;
        }
    }

    visi[node] = false;
    return dp[node][distance] = ans;
}

int countPaths(int n, vector<vector<int>> &roads)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto i : roads)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    vector<int> visi(n, false);

    int shortestPath = dijkstra(adj, n, 0);
    vector<vector<int>> dp(n + 1, vector<int>(shortestPath + 1, -1));

    return solveMem(0, n - 1, adj, visi, shortestPath, shortestPath, dp);
}

// leetcode
int countPaths(int n, vector<vector<int>> &roads)
{
    const long long MOD = 1e9 + 7;
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < roads.size(); i++)
    {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;

    vector<long long> time_to_reach(n, LONG_MAX);
    vector<long long> ways(n, 0);

    pq.push({0, 0});
    time_to_reach[0] = 0;
    ways[0] = 1;

    while (!pq.empty())
    {
        long long time = pq.top().first;
        long long node = pq.top().second;

        pq.pop();

        if (time > time_to_reach[node])
            continue;

        for (auto it : adj[node])
        {
            long long nxt_node = it.first;
            long long new_time = it.second;

            if (time_to_reach[nxt_node] > time + new_time)
            {
                time_to_reach[nxt_node] = time + new_time;
                ways[nxt_node] = ways[node];
                pq.push({time_to_reach[nxt_node], nxt_node});
            }
            else if (time_to_reach[nxt_node] == time + new_time)
            {
                ways[nxt_node] = (ways[nxt_node] + ways[node]) % MOD;
            }
        }
    }

    return ways[n - 1] % MOD;
}
