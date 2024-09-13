#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

vector<int> topo(vector<vector<int>> &richer, int n)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < richer.size(); i++)
    {
        int u = richer[i][0];
        int v = richer[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(n);

    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neigh : adj[front])
        {

            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    return ans;
}

int search(vector<int> &toposorted, int i)
{
    for (int j = 0; j < toposorted.size(); j++)
    {
        if (toposorted[j] == i)
        {
            return j;
        }
    }
    return -1;
}

vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{

    int n = quiet.size();
    vector<int> toposorted = topo(richer, n);

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        int mini = INT_MAX;
        int minIndex = -1;
        int index = search(toposorted, i);

        for (int z = 0; z <= index; z++)
        {

            if (quiet[toposorted[z]] < mini)
            {
                mini = quiet[toposorted[z]];
                minIndex = toposorted[z];
            }
        }
        ans[i] = minIndex;
    }
    return ans;
}

// 2nd
void dfs(int node, vector<bool> &visited, vector<int> adj[], stack<int> &st)
{
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (visited[child])
            continue;
        dfs(child, visited, adj, st);
    }
    st.push(node);
}

vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
    int n = quiet.size();
    vector<int> ans(n, 0);
    stack<int> order;
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
        ans[i] = i;

    for (auto vec : richer)
    {
        adj[vec[0]].push_back(vec[1]);
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, visited, adj, order);
    }

    while (!order.empty())
    {
        int node = order.top();
        order.pop();

        for (auto child : adj[node])
        {
            if (quiet[ans[child]] > quiet[ans[node]])
                ans[child] = ans[node];
        }
    }
    return ans;
}

