#include <bits/stdc++.h>

using namespace std;

// << ,


long long maxScore(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n);
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    vector<pair<int, int>> pq;  
    for (int i = 0; i < n; i++) {
        pq.push_back({degree[i], i});
    }

    sort(pq.begin(), pq.end());

    unordered_map<int, int> value;
    for (int i = 0; i < n; i++) {
        value[pq[i].second] = i+1;  
    }

    long long ans = 0;

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        ans += 1LL * value[u] * value[v];
    }

    return ans;
}




long long maxScore(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n);
    unordered_map<int, list<int>> adj;

    for(int i = 0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    vector<pair<int, int>> pq;
    
    for(int i = 0; i<n; i++) {
        pq.push_back({degree[i], i});
    }

    sort(pq.begin(), pq.end());

    int cnt = 1;
    unordered_map<int, int> value;

    for(int i = 0; i<n; i++) {
        auto toppp = pq[i];

        value[toppp.second] = cnt;
        cnt++;
    }

    queue<int> q;
    int src = pq[n-1].second;
    q.push(src);
    vector<bool> visi(n);
    visi[src] = true;

    int ans = 0;

    while (!q.empty())
    {
        int toppp = q.front();
        q.pop();

        for(auto neigh : adj[toppp]) {

            if(!visi[neigh]) {
                ans = ans + value[toppp]*value[neigh];
                visi[neigh] = true;
                q.push(neigh);
            }
        }
    }

    return ans;
}