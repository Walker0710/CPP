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

inline const auto optimize = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    unordered_map<int, list<int>> adj;
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    
    while (!q.empty())
    {
        int tp = q.front();
        q.pop();
        for (auto it : adj[tp])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    
    return vis[destination];
}