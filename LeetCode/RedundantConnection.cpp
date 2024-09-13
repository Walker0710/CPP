#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neigh : adj[node])
    {
        if (!visited[neigh])
        {
            if (isCyclicDFS(neigh, node, visited, adj))
                return true;
        }
        else if (neigh != parent)
            return true;
    }

    return false;
}

bool cycleDetection(vector<vector<int>> &edges, int n)
{
    unordered_map<int, list<int>> adj;

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDFS(i, -1, visited, adj))
                return true;
        }
    }
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;

    for (int i = edges.size() - 1; i >= 0; i--)
    {
        edges.erase(edges.begin() + i);

        bool isCyclePresent = cycleDetection(edges, n);

        if (!isCyclePresent)
        {
            return edges[i];
        }

        // Restore the removed edge
        edges.insert(edges.begin() + i, {edges[i][1], edges[i][0]});
    }

    return {};
}

// 2nd approch
int findParent(vector<int> &parent, int node) {

    if(parent[node] == node)
    return node;

    return findParent(parent, parent[node]);
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {

    for(int i = 0; i<n; i++) {

        parent[i] = i;
        rank[i] = 0;
    }
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

    if(rank[u] < rank[v]) 
    parent[u] = v;

    else if(rank[v] < rank[u]) 
    parent[v] = u;

    else {

        parent[v] = u;
        rank[u]++;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {

    int n = edges.size() + 1;

    vector<int> parent(n);
    vector<int> rank(n);
    vector<int> ans;

    makeSet(parent, rank, n);

    for(int i = 0; i<n-1; i++) {

        int first = edges[i][0];
        int second = edges[i][1];

        int firstParent = findParent(parent, first);
        int secondParent = findParent(parent, second);

        if(firstParent == secondParent) {

            ans = {first, second};
        }

        else {

            unionSet(firstParent, secondParent, parent, rank);
        }
    }

    return ans;
}
