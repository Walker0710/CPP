#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(i);
        vector<bool> visi(n);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neigh : adj[node])
            {
                if (!visi[neigh])
                {
                    ans[i].push_back(neigh);
                    q.push(neigh);
                    visi[neigh] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(ans[i].begin(), ans[i].end());
    }

    return ans;
}
