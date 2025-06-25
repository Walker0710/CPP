#include <bits/stdc++.h>

using namespace std;

// << ,

int ans = 0;
vector<int> adj[100005];

int dfs(int node, int parent)
{
    int size = 1;
    unordered_map<int, int> mp;
    
    for (auto child : adj[node])
    {
        if (child != parent)
        {
            int subtree = dfs(child, node);
            size += subtree;
            mp[subtree]++;
        }
    }
 
    if (mp.size() <= 1)
    ans++;
    
    return size;
}

int countGoodNodes(vector<vector<int>> &edges)
{
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(0, -1);
    return ans;
}