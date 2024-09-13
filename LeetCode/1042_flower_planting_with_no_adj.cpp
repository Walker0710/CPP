#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

void bfs(int node, unordered_map<int, list<int>> &adj, vector<int> &ans, vector<bool> &visi)
{
    queue<pair<int, int>> q;
    q.push({node, 1});
    visi[node] = true;
    ans[node - 1] = 1;

    while (!q.empty())
    {
        int gar = q.front().first;
        int col = q.front().second;
        q.pop();

        int colourTo = 1;

        for (auto i : adj[gar])
        {

            if (!visi[i])
            {

                if (colourTo == col)
                {
                    colourTo++;
                }

                ans[i - 1] = colourTo;
                q.push({i, colourTo});
                visi[i] = true;
                colourTo++;
            }
        }
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    unordered_map<int, list<int>> adj;

    for (auto i : paths)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> ans(n);
    vector<bool> visi(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (!visi[i])
        {
            bfs(i, adj, ans, visi);
        }
    }
    return ans;
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    vector<vector<int>> adj(n + 1);
    vector<int> flowergarden(n + 1);
    vector<int> vis(n + 1, 0);

    for (auto it : paths)
    {
        int s = it[0];
        int d = it[1];
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            flowergarden[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node])
                {
                    if (!vis[neighbor])
                    {
                        // Find available colors for the neighbor
                        vector<int> col(5, 0);
                        for (auto i : adj[neighbor])
                        {
                            col[flowergarden[i]] = 1;
                        }

                        // Assign the first available color to the neighbor
                        for (int k = 1; k < 5; ++k)
                        {
                            if (col[k] == 0)
                            {
                                flowergarden[neighbor] = k;
                                break;
                            }
                        }

                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    return vector<int>(flowergarden.begin() + 1, flowergarden.end());
}