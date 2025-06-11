#include <bits/stdc++.h>

using namespace std;

// << ,

pair<int, int> res{0, 1};
int depth[50001] = {};

void dfs(int i, int p, unordered_map<int, list<pair<int, int>>> &adj, vector<int> &nums, int left, int curr_depth, vector<int> &pref) {
    int prev_depth = depth[nums[i]];
    depth[nums[i]] = curr_depth;

    left = max(left, prev_depth);

    res = min(res, {-(pref.back() - pref[left]), curr_depth - left});

    for(auto &[j, l] : adj[i]) {
        if(j != p) {
            pref.push_back(pref.back() + l);
            dfs(j, i, adj, nums, left, curr_depth+1, pref);
            pref.pop_back();
        }
    }

    depth[nums[i]] = prev_depth;
}



vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back({v, edges[i][2]});
        adj[v].push_back({u, edges[i][2]});
    }

    vector<int> pref{0};

    dfs(0, -1, adj, nums, 0, 1, pref);

    return {-res.first, res.second};
}