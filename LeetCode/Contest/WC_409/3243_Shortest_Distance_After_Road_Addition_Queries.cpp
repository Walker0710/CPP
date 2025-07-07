#include <bits/stdc++.h>

using namespace std;

// << ,

int minTimeToReach(unordered_map<int, list<int>> &adj, int n) 
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;
    vector<int> dp(n, INT_MAX); // shortest distance from node 0

    minH.push({0, 0});

    while (!minH.empty())
    {
        vector<int> yoo = minH.top();
        minH.pop();

        int t = yoo[0];
        int r = yoo[1];

        if (dp[r] <= t)
            continue;

        dp[r] = t;

        if (r == n - 1)
            return t;

        for (auto &neigh : adj[r])
        {
            minH.push({t + 1, neigh});
        }
    }

    return -1;
}


vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < n - 1; i++) {
        adj[i].push_back(i + 1);
    }

    vector<int> ans;

    for (int i = 0; i < queries.size(); i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        adj[u].push_back(v);

        ans.push_back(minTimeToReach(adj, n));
    }

    return ans;
}


// 2nd approch
int bfs(int start, int end, int n, const vector<vector<int>> &graph)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int u : graph[curr])
        {
            if (dist[u] > dist[curr] + 1)
            {
                dist[u] = dist[curr] + 1;
                q.push(u);
            }
        }
    }

    return dist[end];
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    vector<int> answer;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++)
    {
        graph[i].push_back(i + 1);
    }

    for (auto query : queries)
    {
        int u = query[0], v = query[1];
        graph[u].push_back(v);
        answer.push_back(bfs(0, n - 1, n, graph));
    }

    return answer;
}