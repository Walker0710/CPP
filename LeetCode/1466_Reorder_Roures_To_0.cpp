#include <iostream>
#include<unordered_map>
#include <vector>

using namespace std;

int ans = 0;
void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis, int m)
{
    vis[m] = true;
    for (auto i : adj[m])
    {
        if (i >= 0)
        {
            if (!vis[i])
            {
                dfs(adj, vis, i);
            }
        }
        else
        {
            i = abs(i);
            if (!vis[i])
            {
                ans++;
                dfs(adj, vis, i);
            }
        }
    }
}

int minReorder(int n, vector<vector<int>> &connections)
{
    int s = connections.size();
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> vis;

    for (int i = 0; i < s; i++)
    {
        adj[connections[i][1]].push_back(connections[i][0]);
        adj[connections[i][0]].push_back(-connections[i][1]);
    }

    dfs(adj, vis, 0);

    if (ans == 0)
        return ans;

    return ans;
}
