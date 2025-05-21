#include <bits/stdc++.h>

using namespace std;

// << ,

void dfs(const string &src, unordered_map<string, deque<string>> &adj, vector<string> &res)
{
    while (!adj[src].empty())
    {
        string dst = adj[src].back();
        adj[src].pop_back();
        dfs(dst, adj, res);
    }
    res.push_back(src);
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_map<string, deque<string>> adj;

    for (int i = 0; i < tickets.size(); i++)
    {
        adj[tickets[i][0]].push_back(tickets[i][1]);
    }

    for (auto &[src, dest] : adj)
    {
        sort(dest.rbegin(), dest.rend());
    }

    vector<string> res;
    dfs("JFK", adj, res);
    reverse(res.begin(), res.end());

    return res;
}