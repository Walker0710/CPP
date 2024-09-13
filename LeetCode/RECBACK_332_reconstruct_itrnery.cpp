#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <string>

using namespace std;

void dfs(string src, unordered_map<string, list<pair<string, bool>>> &adj, vector<string> &ans) {
    for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
        if (!it->second) {
            it->second = true;
            dfs(it->first, adj, ans);
            ans.push_back(it->first);
        }
    }
}

vector<string> findItinerary(vector<vector<string>> &tickets) {
    unordered_map<string, list<pair<string, bool>>> adj;

    for (int i = 0; i < tickets.size(); i++) {
        adj[tickets[i][0]].push_back({tickets[i][1], false});
    }

    // Sort the adjacency list to ensure lexical order
    for (auto &pair : adj) {
        pair.second.sort();
    }

    string src = "JFK";
    vector<string> ans;
    dfs(src, adj, ans);
    ans.push_back(src);
    reverse(ans.begin(), ans.end());
    return ans;
}

