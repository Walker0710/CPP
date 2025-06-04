#include <bits/stdc++.h>

using namespace std;

// << ,

int lent = 0;
int cnt = 0;

vector<int> trace;

void DFS(int node, int parent, int top, int down, int sum, vector<int> &path, vector<int> &nums, int twice)
{
}

vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
{
    unordered_map<int, list<pair<int, int>>> adj;
    trace.resize(50001, -1);

    for (auto &edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    dfs(0, -1, 0, 0, 0, path, nums, -1, adj);

    return {lent, cnt};
}