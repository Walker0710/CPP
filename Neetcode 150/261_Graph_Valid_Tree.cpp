#include <bits/stdc++.h>

using namespace std;

// << ,

bool isCyclicDFS(int node, int parent, vector<bool> &visi, unordered_map<int, list<int>> &adj)
{
    visi[node] = true;

    for (auto neigh : adj[node])
    {

        if (!visi[neigh])
        {

            bool cycle = isCyclicDFS(neigh, node, visi, adj);

            if (cycle)
                return true;
        }

        else if (neigh != parent)
            return true;
    }

    return false;
}

bool validTree(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visi(n, false);

    if (isCyclicDFS(0, -1, visi, adj))
    return false;

    for (bool v : visi)
    {
        if (!v)
        return false; 
    }

    return true;
}